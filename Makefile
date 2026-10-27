CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2
SOURCES := $(wildcard src/*.c)
PROGRAMS := $(patsubst src/%.c,bin/%,$(SOURCES))
.PHONY: all test clean
all: $(PROGRAMS)
bin/%: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@
test: all
	sh tests/test_all.sh
clean:
	rm -rf bin
