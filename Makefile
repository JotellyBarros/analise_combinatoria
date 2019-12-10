SCRIPTPATH = `dirname $0`
PRODUCTHOME = ${SCRIPTPATH}
LIB_PATH = ${PRODUCTHOME}
LD_LIBRARY_PATH = $(LIB_PATH)
export LD_LIBRARY_PATH

CC = gcc 

CFLAGS = -Wall -O -export-dynamic -D__linux__ -D_LINUX_

all: split.o table.o trim.o combinatoria.o combinatoria

split.o: split.c split.h
	$(CC) $(CFLAGS) -c -o split.o split.c

table.o: table.c table.h
	$(CC) $(CFLAGS) -c -o table.o table.c

trim.o: trim.c trim.h
	$(CC) $(CFLAGS) -c -o trim.o trim.c

combinatoria.o: combinatoria.c
	$(CC) $(CFLAGS) -c combinatoria.c -o combinatoria.o

combinatoria: split.o table.o trim.o combinatoria.o
	$(CC) $(CFLAGS) split.o table.o trim.o combinatoria.o -o combinatoria

# clean:
	# rm -f combinatoria*.o *.bak *~ skins/*/*.bak skins/*/*~
