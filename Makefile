override DEBUG=		# -DDEBUG for debugging logs
CC=gcc
BIN=example
TEST=test/test.c
OBJS=stack.o

all: $(BIN)

%.o: %.c %.h
	$(CC) $(DEBUG) -c $< -o $@

%.o: %.c
	$(CC) $(DEBUG) $^ -o $@

$(BIN): $(BIN).c $(OBJS)
	$(CC) $(DEBUG) $^ -o $@.out

test: $(TEST) $(OBJS)
	$(CC) $(DEBUG) $^ -o $@.out
	./test.out

clean:
	rm -f *.exe *.o *.out
