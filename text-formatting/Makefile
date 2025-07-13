CC = gcc
CFLAGS = -g

OBJS = fmt.o word.o line.o
TARGET = fmt

$(TARGET): fmt.o word.o line.o
  $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
fmt.o: word.h line.h fmt.c
	$(CC) $(CFLAGS) -c fmt.c
word.o: word.c word.h
	$(CC) $(CFLAGS) -c word.c
line.o: line.c line.h
	$(CC) $(CFLAGS) -c line.c
	
clean:
	rm -f *.o
