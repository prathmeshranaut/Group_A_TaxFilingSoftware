CC=gcc
INCLUDE= -I./include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors $(INCLUDE)
SRC = src/guide.c src/userDetails.c
LIBOBJ = cJSON.o

_OBJS = build/cJSON.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

libs: include/cJSON.c
	$(CC) $(CFLAGS) -c $?

all: src/main.c $(SRC)
	$(CC) $(CFLAGS) $(LIBOBJ) $? -o tax
