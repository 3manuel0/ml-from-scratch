CC = gcc

TARGET = ml

OBJS = main.o src/linear.o

CFLAGS = -Wall -std=c99 -Wextra -Werror

Links = -Llib -lc3sv -l3man 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(Links)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o