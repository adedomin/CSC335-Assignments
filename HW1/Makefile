CC=cc
CFLAGS=-Wall --std=c99 -O0
NAME=gcd
DEPS=
OBJ=gcd.o

DOC=grip
DOCFLAGS=--export
DOCS=doc/hw1.html

all: $(OBJ) executable clean $(DOCS)
	
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.html: %.md
	$(DOC) $< $@ $(DOCFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
