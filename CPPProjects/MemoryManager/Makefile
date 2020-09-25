main:  MemoryManager.o blocknode.o testMemMgr.o
	g++ -std=c++11 blocknode.o MemoryManager.o testMemMgr.o -o main

testMemMgr.o:  testMemMgr.cpp
	g++ -std=c++11 -c testMemMgr.cpp

blocknode.o: blocknode.h blocknode.cpp 
	g++ -std=c++11 -c blocknode.cpp

MemoryManager.o: MemoryManager.cpp MemoryManager.h
	g++ -std=c++11 -c MemoryManager.cpp

clean:
	rm *.o
