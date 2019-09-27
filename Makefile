CC=gcc
CFLAGS=-O2 -fopenmp

targets := ex1 ex1-ameliore ex-for ex-task ex-single ex-barrier

all: $(targets)

$(targets): %: %.c
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	for target in $(targets); do \
		rm -f $$target ; \
	done
