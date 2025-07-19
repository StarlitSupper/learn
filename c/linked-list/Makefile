CC = gcc
CFLAGS = -g

TARGET = list
OBJS = main.o list.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
main.o: list.h main.c
	$(CC) $(CFLAGS) -c main.c
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c
	
clean:
	rm -f *.o
