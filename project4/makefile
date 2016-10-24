all: PA04

PA04: PA04.o Bubble.o Merge.o
	g++ PA04.o Bubble.o Merge.o -o PA04

PA04.o: PA04.cpp
	g++ -c PA04.cpp

Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp

Merge.o: Merge.cpp
	g++ -c Merge.cpp

clean:
	rm -f *.o PA04
