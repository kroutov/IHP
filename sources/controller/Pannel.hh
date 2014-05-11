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

#ifndef PANEL_HH
#define PANEL_HH

#define PANEL_DFLT_NAME	"IHP controler"

#include <string>
#include <gtkmm/window.h>
#include <gtkmm/notebook.h>
#include "tabs/state/state.hh"

using namespace std;

class 		Pannel: public Gtk::Window
{
public:
	Pannel();					/**< Default constructor. */

private:
	string 				name;			/**< Window name. */
	Gtk::Notebook 		tablist;		/**< Tabs. */
	tabs::state 		state;
};

#endif