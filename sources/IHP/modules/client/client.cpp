#include "client.hh"

client::client()
{

}

client::~client()
{
	
}

void 	client::configure(KSocket *_sock, signed int _oport, KLog *_log,
						  iFirewall *_firewall, KModule<iIDS> &KMIDS)
{
	isock = _sock;
	oport = _oport;
	osock.setPort(oport);
	log   = _log;

	firewall = _firewall;
	if (!firewall)
		log->write(WARNING, "NULL firewall instance provided");

	try
	{
		IDS      = KMIDS.create();
	}
	catch (KError *error)
	{
		log->write(WARNING, "Unable to create an IDS instance");
	}
}

void 				*client::tmain(__attribute__((unused)) void *args)
{
	char 			buffer[16];
	int 			ret;

	name.assign(isock->getSaddr()->getAddress());
	name += ":";
	name += static_cast<ostringstream*>( &(ostringstream() << isock->getSaddr()->getPort()) )->str();

	if (firewall)
	{
		if (firewall->check(isock->getSaddr()->getAddress()) == true)
		{
			if (log) {log->write(WARNING, name + ": IP is blacklisted");}
			cout << "Firewall detection: blocked" << endl;
			osock.disconnect();
			isock->disconnect();
			return(NULL);
		}
	}
	else
		if (log) {log->write(INFO, name + ": No firewall instance available");}
			

	try
	{
		osock.connect();
		spot.add(&osock, KSocket::pool::READ);
		spot.add(isock, KSocket::pool::READ);

		if (log) {log->write(name + ": connected");}
		while (true)
		{
			spot.select();

			if (spot.isset(isock, KSocket::pool::READ))
			{
				memset(buffer, 0, 16);

				while (isock->isReadable())
				{
					//cout << "-- Socket is readable --" << endl;
					ret = isock->receive(buffer, 15);
					//cout << " read  : " << ret << endl;
					ret = osock.send(buffer, ret);
					//cout << " write : " << ret << endl;
				}
			}

			if (spot.isset(&osock, KSocket::pool::READ))
			{
				memset(buffer, 0, 16);
				ret = osock.receive(buffer, 15);
				ret = isock->send(buffer, ret);
			}
		}
	}
	catch(KError *error)
	{
		if (log) {log->write(ERROR, name + ": " + error->what());}
	}

	if (log) {log->write(name + ": disconnection");}
	osock.disconnect();
	isock->disconnect();
	return(NULL);
}
