CC=gcc
INCLUDE= -I./include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors $(INCLUDE)
SRC = src/guide.c src/userDetails.c

_OBJS = cJSON.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

libs: include/cJSON.c
	$(CC) $(CFLAGS) -c $?

all: src/main.c $(SRC)
	$(CC) $(CFLAGS) $? -o tax
