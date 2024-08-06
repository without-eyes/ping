CC = gcc
CFLAGS = -g -Wall -I$(IDIR) -o

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

.PHONY: all
.SILENT: all

all: clean myping

myping:
	$(CC) $(SOURCES) $(CFLAGS) $@

clean:
	rm -f ./myping