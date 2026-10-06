CC      := gcc
CFLAGS  := -Wall -Wextra -Iinc
LDLIBS  := -lm

SRCS    := $(wildcard src/*.c)
OBJS    := $(patsubst src/%.c, build/%.o, $(SRCS)) # patsubst = pattern substitution, e.g. swaps src/main.c into build/main.o
TARGET  := typr

.PHONY: all clean

all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDLIBS)

# Compiling
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build $(TARGET)