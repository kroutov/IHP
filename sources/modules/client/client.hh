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

#ifndef CLIENT_HP
#define CLIENT_HP

#include <iostream>
#include <sstream>
#include <KSocket.hh>
#include <KThread.hpp>
#include <KMutex.hh>
#include <KModule.hpp>
#include "../../iClient.hpp"

using namespace std;
using namespace KNM;

/**
 * A default client class.
 * It does nothing.
 */
class 	client: public iClient
{
public:
	client();											/**< Should be the ONLY constructor. */
	~client();											/**< Destructor. */

	void 	configure(KSocket *, signed int, KLog *,
					  iFirewall *, KModule<iIDS>&);		/**< Configure client. */
	void 	*tmain(void *args);							/**< Thread main function. */

private:
	KSocket 		*isock;								/**< Client Input socket. */
	KSocket 		osock;								/**< Client Output socket. */
	signed int 		oport;								/**< Client Output port. */
	KLog 			*log;								/**< Log system instance. */
	KSocket::pool 	spot;								/**< Socket pool for I/O operations. */
	string 			name;								/**< Client 'name' for log readability. */
	iIDS 			*IDS;								/**< IDS instance. */
	iFirewall 		*firewall;							/**< Firewall instance. */
};

/**
 * Module factory.
 */
extern "C" iClient 	*build()
{
    return new client;
}

/**
 * Module destructor.
 */
extern "C" void 	destroy(iClient *_module)
{
	if (_module)
		delete _module;
}

#endif