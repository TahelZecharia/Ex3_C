CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_stringFunctions=stringFunctions.o
FLAGS=-g -Wall

all: stringProg

stringProg: $(OBJECT_MAIN) libString
	$(CC) $(FLAGS) -o stringProg $(OBJECT_MAIN) libString.a 

libString: libString.a
libString.a: $(OBJECT_stringFunctions) 
	$(AR) -rcs libString.a $(OBJECT_stringFunctions) 

main.o: main.c stringFunctions.h  
	$(CC) $(FLAGS) -c main.c

stringFunctions.o: stringFunctions.c  
	$(CC) $(FLAGS) -c stringFunctions.c 

.PHONY: all clean

clean:
	rm -f *.o *.a stringProg 