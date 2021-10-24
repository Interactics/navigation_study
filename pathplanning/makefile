CC=g++
CFLAGS= -o
OBJS=pathplanning.cpp
TARGET=pathplanning.bin

all: $(TARGET)
 
clean:
	rm -rf *.o
		rm -rf $(TARGET)
	 
$(TARGET): $(OBJS)
					$(CC) $(CFLAGS) $@ $(OBJS)
pathplanning.o: pathplanning.cpp
