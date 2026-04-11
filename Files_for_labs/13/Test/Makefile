PROG = run
CC = gcc
SRCS = main.c factorial.c
HDRS = factorial.h
OBJS = $(SRCS:.c=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

clean:
	rm -f $(OBJS)

.c.o : $(HDRS) ; $(CC) -c $*.c