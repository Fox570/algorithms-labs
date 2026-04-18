CC = gcc
CFLAG = -Iinclude

SRCS = 	src/printf.c\
		src/scanf.c\
		src/main.c

INCLS = include/_stdio.h
	
OBJS = $(SRCS:.c=.o)

PROG = run

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAG) -o $@ $(OBJS)

src/%.o: src/%.c $(INCLS)
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f src/*.o $(PROG)