.PHONY: all clean flash

all:	test
	./test

test:	iom.c test.c
	gcc -o $@ test.c

iom.c:	iom.csv
	/usr/bin/python3 convert.py < $< > $@

clean:
	rm -f iom.c test
