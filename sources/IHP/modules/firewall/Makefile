# Makefile for ihp client module.
# 
# Author: Jean-Philippe Clipffel
#

NAME 			= 		firewall.so
SRC			=		Firewall.cpp
CC			=		g++
CFLAGS			=		-W -Wall -pthread
INCLUDES 		=		../../../libKNM/includes

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
			mv $(NAME) ../../../../