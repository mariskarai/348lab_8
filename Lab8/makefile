# Compiler
CC = gcc


CFLAGS = -Wall -std=c11
TARGETS = football temperature

all: $(TARGETS)
football: Task1.c
	$(CC) $(CFLAGS) Task1.c -o football
temperature: Task2.c
	$(CC) $(CFLAGS) Task2.c -o temperature
clean:
	rm -f $(TARGETS) *.o
run_football: football
	./football
run_temperature: temperature
	./temperature