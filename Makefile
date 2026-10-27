CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2
SOURCES := $(wildcard src/*.c)
PROGRAMS := $(patsubst src/%.c,bin/%,$(SOURCES))
.PHONY: all test clean
all: $(PROGRAMS)
bin/%: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@ $(if $(filter q19_triple_des_cbc q33_des_block_cipher,$*),-lcrypto,)
test: all
	sh tests/test_all.sh
	sh tests/test_40.sh
clean:
	rm -rf bin
