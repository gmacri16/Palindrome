#Gregory Macri
#
#
#
#Makefile for palindrom program
#

CFILES=palindrom.c timer.c
OFILES=$(CFILES:.c=.o)
CC=gcc -g -Wall

palindrom:	$(OFILES)
	$(CC) -o pal $(OFILES)

clean::
	/bin/rm -f pal $(OFILES)
