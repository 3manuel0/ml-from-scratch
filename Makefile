CC = gcc

TARGET = ml

OBJS = main.o src/linear.o src/matrix.o

CFLAGS = -Wall -std=c99 -Wextra -Werror

ifeq ($(OS),Windows_NT)# for BCryptGenRandom in windows I need -lbcrypt
Links = -Llib -lc3sv -l3man -lm
else
Links = -Llib -lc3sv -l3man -lm
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(Links)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o