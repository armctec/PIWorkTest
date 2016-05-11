CC=gcc
CFLAGS=-c
LDFLAGS=-lbcm2835

SRCS = main.c \
       displaypx.c

OBJS = $(SRCS:.c=.o)

all: main.exe


%.o: %.c
	$(CC) $(CFLAGS) -o ../obj/$@ $<

main.exe: $(OBJS)
	$(CC) -o ../main $(wildcard ../obj/*.o) $(LDFLAGS)

.PHONY: clean
clean:
	rm ../obj/*.o
	rm ../main
