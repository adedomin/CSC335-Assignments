CC=cc
CFLAGS=-Wall --std=c99 -O0
NAME=gcd
DEPS=
OBJ=gcd.o

all: $(OBJ) executable clean
	
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm $(OBJ)

remove:
	rm $(NAME)
