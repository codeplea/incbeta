CCFLAGS ?= -Wall -Wshadow -O2 -g
LFLAGS ?= -lm


all: test


test: test.o incbeta.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LFLAGS)
	./$@


.c.o:
	$(CC) -c $(CCFLAGS) $< -o $@


clean:
	rm -f *.o
	rm -f *.exe
