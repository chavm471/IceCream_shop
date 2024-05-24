CC = g++
	
FLAGS = -std=c++17 *.cpp -g -Wall -Werror
	
PROG = shop
	
#these are source files
SRCS = dessert.cpp btree.cpp main.cpp
	
OBJ1 = dessert.o
	
OBJ2 = btree.o
	
OBJ3 = main.o
	
#defining headers
HEADERS = dessert.h btree.h
	
all: $(PROG)
	
$(PROG): $(OBJ1) $(OBJ2) $(OBJ3)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ1) $(OBJ2) $(OBJ3)
	
#these below dont need -o
$(OBJ1): dessert.cpp $(HEADERS)
	$(CC) $(FLAGS) -c dessert.cpp
	
$(OBJ2): btree.cpp $(HEADERS)
	$(CC) $(FLAGS) -c btree.cpp
	
$(OBJ3): main.cpp $(HEADERS)
	$(CC) $(FLAGS) -c main.cpp
	
clean:
	rm -f $(PROG) *.o *~ \#*
