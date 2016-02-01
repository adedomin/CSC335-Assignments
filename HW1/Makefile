CC=cc
CFLAGS=-Wall --std=c99 -O0
NAME=gcd
DEPS=
OBJ=gcd.o

DOC=pandoc
DOCFLAGS=
DOCNAME=./doc/hw1.pdf
DOCOBJ=./doc/hw1.md

PACK=zip
PACKFLAGS=-r
PACKNAME=HW1-dedominica.zip
PACKDIR=../HW1


all: $(OBJ) executable clean
	
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)

make_doc:
	$(DOC) $(DOCOBJ) -o $(DOCNAME) $(DOCFLAGS)

remove_doc:
	rm $(DOCNAME)

make_package:
	$(PACK) $(PACKFLAGS) $(PACKNAME) $(PACKDIR)

remove_package:
	rm $(PACKNAME)
