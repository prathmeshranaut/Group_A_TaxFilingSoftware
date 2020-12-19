ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
CC=gcc
INCLUDE= -I../include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors $(INCLUDE)
_SRC = $(wildcard src/*.c)
_TEST_SRC = $(wildcard test/src/*.c) $(filter-out src/main.c, $(wildcard src/*.c))
_LIB_SRC= include/cJSON.c include/pdfgen.c test/include/unity.c
LIBOBJ = cJSON.o pdfgen.o
TEST_LIBOBJ = cJSON.o unity.o pdfgen.o

SRC = $(patsubst %,$(ROOT_DIR)/%,$(_SRC))
TEST_SRC = $(patsubst %,$(ROOT_DIR)/%,$(_TEST_SRC))
LIB_SRC = $(patsubst %,$(ROOT_DIR)/%,$(_LIB_SRC))

all: libs compile

libs: $(LIB_SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) -c $?

compile: $(SRC)
	mkdir -p build && mkdir -p bin && cd build && $(CC) $(CFLAGS) $(LIBOBJ) $? -o ../bin/tax

compile-tests: $(TEST_SRC)
	mkdir -p build && cd build && $(CC) $(CFLAGS) $(TEST_LIBOBJ) $? -o tax_test
	./build/tax_test | sed -n -e 's/^.*test\/\([^\S]*\):\([^\D]*\).*$$/test\/\1:\2/p' -e 's/-----------------------/-----------------------/p' -e 's/OK/OK/p' -e 's/FAIL/FAIL/p' -e 's/\([d]* Tests\)/\1/p' > test.log

docs:
	doxygen Doxyfile

tests: all compile-tests

test: tests

clean:
	rm -rf build/*
	rm -rf bin/*
	rm test.log