CC = gcc 
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Wvla -Werror
OBJ = ./main.o
BIN = project

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)
clean:
	$(RM) $(OBJ) $(BIN)
