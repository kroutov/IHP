# Makefile for ihp - Intelligent Honeypot Project
#
# Author        : Jean-Philippe Clipffel
# Creation date : 27/04/2014
# Last update   : 29/04/2014

NAME			=		ihp-server.bin

SRC 			=		main.cpp				\
						server.cpp

CC				=		g++
CFLAGS			=		-W -Wall -pthread
CLIBS			=		-lKNM
INCLUDES 		=		/usr/local/include/libKNM

.PHONY: 	all clean flcean re install

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(CLIBS) -I $(INCLUDES) $(SRC) -o $(NAME)

clean:	

fclean:		clean
			rm -f $(NAME)

re:			fclean all

install:
			if [ -e $(NAME) ]; then mv $(NAME) ../../; fi
