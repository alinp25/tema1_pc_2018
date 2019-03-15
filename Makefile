# build: telefon.o Encoder.o Utils.o Decoder.o
# 	gcc -Wall -std=gnu99 telefon.o Encoder.o Decoder.o Utils.o \
# 		PerfectMessage.o AutoCorrecter.o -O2 -o telefon

CC = gcc
CFLAGS = -std=gnu99 -O2 -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

build: $(OBJ)
	$(CC) -o telefon $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

run: build
	./telefon

clean:
	rm -f ./*.o ./telefon

