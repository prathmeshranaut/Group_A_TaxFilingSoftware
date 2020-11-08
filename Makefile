ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
CC=gcc
INCLUDE= -I../include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors $(INCLUDE)
_SRC = $(wildcard src/*.c)
LIBOBJ = cJSON.o

SRC = $(patsubst %,$(ROOT_DIR)/%,$(_SRC))

libs: include/cJSON.c
	mkdir -p build && cd build && $(CC) $(CFLAGS) -c $(ROOT_DIR)/$?

all: $(SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) $(LIBOBJ) $? -o tax

clean:
	rm -rf build/*