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

#include <signal.h>
#include <string>
#include <KSocket.hh>
#include <KConfig.hh>
#include <KModule.hpp>
#include <KLog.hh>
#include <KError.hh>
#include "iClient.hpp"
#include "iFirewall.hpp"
#include "iIDS.hpp"

using namespace std;
using namespace KNM;

#define IPORT_DFLT 		12000
#define OPORT_DFLT		21
#define LOGFILE_DFLT	"server.log"

class 	server
{
public:
	server();							/**< Default constructor. */
	server(const string &);				/**< Construct with a configuration file path. */
	server(signed int, signed int);		/**< Specify ports. */
	~server();							/**< Destructor. */

	void 	setConf(const string &);	/**< Set configuration file path. */
	void 	configure(int, char**);		/**< (auto)Configure the server. */
	void 	start();					/**< Start the server. */

private:
	signed int 			iport;
	signed int 			oport;
	KSocket 			insock;
	KSocket 			outsock;
	KConfig 			config;
	string 				cfgpath;
	KLog 				logfile;
	KModule<iClient> 	modClient;
	KModule<iFirewall>	modFirewall;
	KModule<iIDS>		modIDS;
};