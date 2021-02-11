CC=g++
CCFLAGS=-std=c++11

XOR: XOR.o
	$(CC) $(CCFLAGS) XOR.o -o XOR

XOR.o: XORANN.cpp
	$(CC) -c -o XOR.o XORANN.cpp $(CCFLAGS)

run:
	./XOR

clean:
	@rm -f *.o
	@rm XOR
