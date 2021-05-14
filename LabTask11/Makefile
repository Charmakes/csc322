SHELL = /bin/sh

OBJS =  mystrings.o Person.o NameAge.o
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS = -lm

mystrings:${OBJ}
   ${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
   -rm -f *.o core *.core

.cpp.o:
   ${CC} ${CFLAGS} ${INCLUDES} -c $< 
