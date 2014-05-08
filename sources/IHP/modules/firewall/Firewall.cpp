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

#include			<iostream>
#include			<fstream>
#include			<string>
#include			<vector>
#include			"Firewall.hh"

using namespace std;

Firewall::Firewall()
{
  
}

Firewall::~Firewall()
{
  
}

void				Firewall::configure(const string& filePath)
{
  ifstream		readFile;
  string			lineRead;

  readFile.open(filePath.c_str());

  if (readFile.is_open())
  {
    while (!readFile.eof())
    {
      readFile >> lineRead;
      this->ipList.push_back(lineRead);
    }
  }
  else
    return;
  readFile.close();
}

bool				Firewall::check(const string& ip)
{
  if (ipList.size() == 0)
    return false;
  for (unsigned int i = 0; i < ipList.size() - 1; i++)
    {
      if (ip == ipList[i])
	return (true);
    }
  return (false);
}
