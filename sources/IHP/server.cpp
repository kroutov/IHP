/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-04-29 11:48:55
* @Last update   : 2014-05-06 12:49:50
*/

#include "server.hh"

void 		server_exit(int __attribute__((unused))_signum, void __attribute__((unused))*_handler)
{
	throw new KError("*", "exit");
}

server::server(){}

server::server(const string &_path)
:cfgpath(_path){}

server::server(signed int _iport, signed int _oport)
:iport(_iport), oport(_oport){}

server::~server()
{
	logfile.write("Shutting down server");
	insock.disconnect();
}

void 	server::setConf(const string &_path)
{
	cfgpath = _path;
}

void 	server::configure(int ac, char **av)
{
	// Configuring configuration file
	cfgpath = KConfig::getopt(ac, av, "-c");

	if (cfgpath.size() > 0)
		config.setSource(cfgpath);
	else
		throw new KError("server::configure()", "no configuration file provided");

	// Configuring port
	iport = config.getIOption("IPORT", IPORT_DFLT);
	oport = config.getIOption("OPORT", OPORT_DFLT);

	//Configure log file
	logfile.setFile(config.getOption("LOGFILE", LOGFILE_DFLT));
	logfile.setMinLevel(INFO);
	logfile.setLevel(INFO);

	// Configuring modCLient
	modClient.setModule(config.getOption("MODCLIENT", "./client.so"));
	modClient.setBuilder("build");
	modClient.setDestroyer("destroy");

	// Configuring modFirewall
	modFirewall.setModule(config.getOption("MODFIREWALL", "./firewall.so"));
	modFirewall.setBuilder("build");
	modFirewall.setDestroyer("destroy");

	// Configuring modIDS
	modIDS.setModule(config.getOption("MODIDS", "./ids.so"));
	modIDS.setBuilder("build");
	modIDS.setDestroyer("destroy");

	// Everything is OK
	logfile.write("Configuration loaded");
}

void 	server::start()
{
	KSocket 	*csock;
	iClient 	*client;
	iFirewall 	*firewall;

	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, (sighandler_t)&server_exit);

	insock.setPort(iport);
	insock.bind();
	insock.listen();
	logfile.write("Input port now connected");

	// Creating a new IDS instance
	try
	{
		firewall = modFirewall.create();
		firewall->configure(config.getOption("FIREWALL_RULES"));
	}
	catch (KError *error)
	{
		firewall = NULL;
		error->dump();
		logfile.write(ERROR, error->what());
	}

	while (1)
	{
		try
		{
			csock = insock.accept();
			logfile.write("New client connected");

			try
			{
				// Creating and configuring a new client instance
				client = modClient.create();
				logfile.write("New client thread created");
				client->configure(csock, oport, &logfile, firewall, modIDS);
				logfile.write("New client thread configured");

				// Starting the client instance
				client->start();
				logfile.write("New client thread started");
			}
			catch (KError *error)
			{
				csock->disconnect();
				error->dump();
				logfile.write(ERROR, error->what());
			}
		}
		catch (KError *error)
		{
			error->dump();
			return;
		}
	}
}

