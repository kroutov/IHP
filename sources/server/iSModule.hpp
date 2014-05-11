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

#ifndef ISMODULE_HPP
#define ISMODULE_HPP

#include <string.h>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include <KLog.hh>

using namespace KNM;

/**
 * Security module interface.
 * Check input packet integrity and security.
 */
class 	iSModule
{
public:
	iSModule(){};
	virtual ~iSModule(){};

	virtual void 	configure(const KConfig &, const KLog &) = 0;	/**< Configure module. */
	virtual void 	input(const char*, size_t) = 0;					/**< Input data. */
	virtual bool 	control() = 0;									/**< Perform security check(s). */
};

#endif