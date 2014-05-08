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

#ifndef IFIREWALL_HPP
#define IFIREWALL_HPP

#include <string.h>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include <KLog.hh>

using namespace KNM;

/**
 * Firewall interface.
 * Firewall check connection validity.
 */
class 	iFirewall
{
public:
	iFirewall(){};
	virtual ~iFirewall(){};

	virtual void 	configure(const string &) = 0;	/**< Configure firewall. */	  
	virtual bool 	check(const string &) = 0;		/**< Check if an IP address is valid. */
};

#endif