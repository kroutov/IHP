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

#include "state.hh"

using namespace tabs;

state::state()
{
	resize(3, 3);

	start.set_label("Start");
	start.set_can_focus(false);
	attach(start, 1, 2, 1, 2, Gtk::SHRINK, Gtk::FILL);

	stop.set_label("Stop");
	stop.set_can_focus(false);
	//attach(stop, 1, 2, 2, 3);
}