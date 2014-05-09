# IHP - Intelligent Honeypot Project
# Copyright (C) 2014 Jean-Philippe Clipffel, Damien Meunier
# Email: jp.clipffel@gmail.com, meunie_d@epitech.eu
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

NAME 			= 		firewall.so
SRC				=		Firewall.cpp
CC				=		g++
CFLAGS			=		-W -Wall -pthread
INCLUDES 		=		../../libKNM/includes

.PHONY: 	all install fclean clean re

all:		$(NAME)

$(NAME):
			@echo "Compiling module $(NAME)"
			$(CC) $(CFLAGS) $(CLIBS) -I $(INCLUDES) -fpic -c $(SRC) -o $(NAME).o
			$(CC) -shared $(NAME).o -o $(NAME)

fclean: 	clean
			rm -f $(NAME)

clean:
			if [ -e $(NAME).o ]; then rm $(NAME).o; fi
			if [ -e $(NAME) ];   then rm $(NAME);   fi

re:			fclean all

install:
			mv $(NAME) ../../../