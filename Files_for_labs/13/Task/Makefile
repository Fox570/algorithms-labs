CC = gcc
CFLAG = -Iinclude

SRC = src/main.c \
      src/run_prog.c \
      src/service_fncs.c \
      src/file_manage_fncs.c \
      src/routes_manage_fncs.c

OBJ = $(SRC:.c=.o)

TARGET = run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $(OBJ)

src/%.o: src/%.c include/funcs.h
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)