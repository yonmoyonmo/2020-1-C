CC = gcc
CFLAGS = -Wall -g -c
INCLUDE = -I
OBJS = hw8Main.o register.o print.o search.o delete.o sort.o
TARGET = PhoneBook04.out

all: $(TARGET)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) phone.dat

