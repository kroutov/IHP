/*
* IHP - Intelligent Honeypot Project
* Copyright (C) 2014 Jean-Philippe Clipffel
* Email: jp.clipffel@gmail.com
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

