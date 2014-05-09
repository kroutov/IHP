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

#ifndef ICLIENT_HPP
#define ICLIENT_HPP

#include <string.h>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include <KThread.hpp>
#include <KLog.hh>
//#include <KModule.hpp>
#include "iFirewall.hpp"
#include "iIDS.hpp"

using namespace KNM;

/**
 * Client interface.
 * Client act as an intelligent proxy and IDS.
 */
class 	iClient: public KThread<>
{
public:
	iClient(){};
	virtual ~iClient(){};

	virtual void 	configure(KSocket *, signed int, KLog *,
							  iFirewall *, KModule<iIDS>&) = 0;		/**< Configure client. */
							  
	virtual void 	*tmain(void *) = 0;								/**< Thread entry point. */
};

#endif