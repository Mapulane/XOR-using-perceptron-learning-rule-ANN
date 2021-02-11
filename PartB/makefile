CC=g++
CCFLAGS=-std=c++11

sigmoid: sigmoid.o
	$(CC) $(CCFLAGS) sigmoid.o -o sigmoid

sigmoid.o: sigmoid.cpp
	$(CC) -c -o sigmoid.o sigmoid.cpp $(CCFLAGS)

run:
	./sigmoid

clean:
	@rm -f *.o
	@rm XOR
