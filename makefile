
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lglfw -lGL -lm

SRC = main.c matrix.c matrix.h vector.c vector.h camera.h camera.c shader.h shader.c
OBJ = $(SRC:.c=.o)
EXEC = cube

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
