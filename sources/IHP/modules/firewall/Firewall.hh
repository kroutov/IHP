/*
* IHP - Intelligent Honeypot Project
* Copyright (C) 2014 Damien Meunier
* Email: meunie_d@epitech.eu
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

#ifndef				_FIREWALL_HH_
# define			_FIREWALL_HH_

#include			"../../iFirewall.hpp"

using namespace std;

class				Firewall : public iFirewall
{

private:
  vector<string>		ipList;

public:
  Firewall();
  ~Firewall();

  void				configure(const string&);
  bool				check(const string&);

};

extern "C" iFirewall*		build()
{
  return new Firewall;
}

extern "C" void			destroy(iFirewall* _module)
{
  if (_module)
    delete _module;
}

#endif				/* _FIREWALL_HH_ */
