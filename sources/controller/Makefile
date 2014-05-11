# Makefile for ihp - Intelligent Honeypot Project
#
# Author        : Jean-Philippe Clipffel
# Creation date : 27/04/2014
# Last update   : 29/04/2014

NAME			=		ihp-controller.bin

SRC 			=		main.cpp				\
						Pannel.cpp				\
						tabs/state/state.cpp 	

CC				=		g++
CFLAGS			=		-W -Wall -pthread
CLIBS			=		-L . ../libKNM/libKNM.so.1.0.0
INCLUDES 		=		../libKNM/includes
GTKMM 			=		`pkg-config gtkmm-3.0 --cflags --libs`

.PHONY: 	all clean flcean re install

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(CLIBS) -I $(INCLUDES) $(SRC) $(GTKMM) -o $(NAME)

clean:	

fclean:		clean
			rm -f $(NAME)

re:			fclean all

install:
			if [ -e $(NAME) ]; then mv $(NAME) ../../; fi
