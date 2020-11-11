ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
CC=gcc
INCLUDE= -I../include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors $(INCLUDE)
_SRC = $(wildcard src/*.c)
_TEST_SRC = $(wildcard test/src/*.c)
_LIB_SRC= include/cJSON.c test/include/unity.c
LIBOBJ = cJSON.o
TEST_LIBOBJ = cJSON.o unity.o

SRC = $(patsubst %,$(ROOT_DIR)/%,$(_SRC))
TEST_SRC = $(patsubst %,$(ROOT_DIR)/%,$(_TEST_SRC))
LIB_SRC = $(patsubst %,$(ROOT_DIR)/%,$(_LIB_SRC))

all: libs compile

libs: $(LIB_SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) -c $?

compile: $(SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) $(LIBOBJ) $? -o ../bin/tax

compile-tests: $(TEST_SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) $(TEST_LIBOBJ) $? -o tax_test
	./build/tax_test

tests: all compile-tests

clean:
	rm -rf build/*