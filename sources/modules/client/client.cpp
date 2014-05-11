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

#include "client.hh"

client::client()
{

}

client::~client()
{
	
}

void 	client::configure(KSocket *_sock, int _oport, KLog *_log, KConfig *_config)
{
	// Configuration
	isock  = _sock;
	oport  = _oport;
	log    = _log;
	config = _config;
	osock.setPort(oport);

	// Retreive client 'name'
	name.assign(isock->getSaddr()->getAddress());
	name += ":";
	name += static_cast<ostringstream*>( &(ostringstream() << isock->getSaddr()->getPort()) )->str();

	// Try to load the IDS module
	if (config)
	{
		modIDS.setModule(config->getOption("MODIDS", "./IDS.so"));
		modIDS.setBuilder("build");
		modIDS.setDestroyer("destroy");
	}
}

void 				*client::tmain(__attribute__((unused)) void *args)
{
	char 			buffer[16];
	int 			ret;

	// Connect to the service
	try
	{
		osock.connect();
		spot.add(&osock, KSocket::pool::READ);
		spot.add(isock, KSocket::pool::READ);
		if (log) {log->write(name + ": connected");}
	}
	catch (KError *error)
	{
		if (log) {log->write(ERROR, name + ": " + error->what());}
		osock.disconnect();
		isock->disconnect();
		return NULL;
	}

	// Proxy loop
	while (true)
	{ 
		try
		{
			spot.select();
			if (spot.isset(isock, KSocket::pool::READ))
			{
				while (isock->isReadable())
				{
					memset(buffer, 0, 16);
					ret = isock->receive(buffer, 15);
					packet.append(buffer, ret);
				}
				osock.send(packet);
				packet.clear();
			}
			if (spot.isset(&osock, KSocket::pool::READ))
			{
				memset(buffer, 0, 16);
				ret = osock.receive(buffer, 15);
				ret = isock->send(buffer, ret);
			}
		}
		catch(KError *error)
		{
			if (log) {log->write(ERROR, name + ": " + error->what());}
			if (log) {log->write(name + ": disconnection");}
			osock.disconnect();
			isock->disconnect();
			break;
		}
	}
	return(NULL);
}
