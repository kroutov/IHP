# Makefile for ihp - Intelligent Honeypot Project
#
# Author        : Jean-Philippe Clipffel
# Creation date : 27/04/2014
# Last update   : 29/04/2014

NAME			=		ihp.bin

SRC_DIR 		=		./sources

SRC 			=		$(SRC_DIR)/IHP/main.cpp				\
						$(SRC_DIR)/IHP/server.cpp

CC				=		g++
CFLAGS			=		-W -Wall -pthread
CLIBS			=		-L . $(SRC_DIR)/libKNM/libKNM.so.1.0.0
INCLUDES 		=		$(SRC_DIR)/libKNM/includes

.PHONY: 	all clean flcean re

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(CLIBS) -I $(INCLUDES) $(SRC) -o $(NAME)

clean:	

fclean:		clean
			rm -f $(NAME)

re:			fclean all
