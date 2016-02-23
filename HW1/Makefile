CC=cc
CFLAGS=-Wall --std=c99 -O0
NAME=gcd
DEPS=
SRC=gcd.c
OBJ=gcd.o

DOC=pandoc
DOCFLAGS=
DOCNAME=./hw1.pdf
DOCOBJ=./hw1.md

PACK=zip
PACKFLAGS=-r
PACKNAME=HW1-dedominica.zip
PACKDIR=HW1/


all: $(OBJ) executable clean
	
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)

doc:
	$(DOC) $(DOCOBJ) -o $(DOCNAME) $(DOCFLAGS)

remove_doc:
	rm $(DOCNAME)

package: doc
	mkdir $(PACKDIR)
	cp $(SRC) $(DOCOBJ) $(DOCNAME) ./Makefile ./HW1/
	$(PACK) $(PACKFLAGS) $(PACKNAME) $(PACKDIR)
	rm -r $(PACKDIR)

remove_package:
	rm $(PACKNAME)
