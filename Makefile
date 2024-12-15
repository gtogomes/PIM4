CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/login.c src/cadastro.c src/relatorio.c src/utils.c
OBJ = $(SRC:.c=.o)
BIN = bin/projeto.exe
TEST = bin/test.exe

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

test: $(OBJ) src/test.c
	$(CC) $(CFLAGS) -o $(TEST) src/test.c $(OBJ)

run:
	./bin/projeto.exe

clean:
	rm -f $(OBJ) $(BIN) $(TEST)
