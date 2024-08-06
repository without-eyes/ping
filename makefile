CC = gcc
CFLAGS = -o -g -Wall

SOURCES = ./src/*.c

.PHONY: all
.SILENT: all

all: ping

%:
	$(CC) $(SOURCES) $(CFLAGS) $@

clean:
	rm -f $@