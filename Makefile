# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -I.  # Include the current directory for headers

# Source and Object Files
SRC = bigint.c main.c
OBJ = bigint.o main.o
TARGET = bigint  # Name of the final executable

# Default target: Compile everything
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile bigint.c into an object file
bigint.o: bigint.c bigint.h
	$(CC) $(CFLAGS) -c bigint.c -o bigint.o

# Compile main.c into an object file
main.o: main.c bigint.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Clean compiled files
clean:
	del /Q *.o bigint.exe 2>nul
