CC=cc
CFLAGS=-Wall --std=c99 -O0
NAME=gcd
DEPS=
OBJ=gcd.o

DOC=pandoc
DOCNAME=./doc/hw1.pdf
DOCOBJ=./doc/hw1.md
DOCFLAGS=-o $(DOCNAME)

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
	$(DOC) $(DOCOBJ) $(DOCFLAGS)

remove_doc:
	rm $(DOCNAME)
