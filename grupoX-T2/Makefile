# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Imodules

# Source files
SRCS = main.c \
       modules/processor.c \
       modules/sorter.c \
       modules/validator.c

# Output executable name
TARGET = tarea2

# Default rule
all: $(TARGET)

# How to build the target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)