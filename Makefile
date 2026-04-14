CC = gcc

TARGET = ml

OBJS = main.o src/linear.o

CFLAGS = -Wall -std=c99 -Wextra -Werror

Links = -Llib -l3man -lc3sv

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(Links)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o