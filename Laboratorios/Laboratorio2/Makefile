
CC = g++
CFLAGS = -Wall
TARGET = biblioteca.exe

SRCS = src\main.cpp src\funciones.cpp
HEADERS = src\funciones.hpp src\libro.hpp

all: $(TARGET) run

$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run:
	./$(TARGET)

clean:
	del $(TARGET)
