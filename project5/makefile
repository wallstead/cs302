all: PA05

PA05: PA05.o Merge.o PrecondViolatedExcept.o
	g++ PA05.o Merge.o PrecondViolatedExcept.o -o PA05

PA05.o: PA05.cpp
	g++ -c PA05.cpp

Merge.o: Merge.cpp
	g++ -c Merge.cpp

# ArrayQueue.o: ArrayQueue.cpp
# 	g++ -c ArrayQueue.cpp

PrecondViolatedExcept.o: PrecondViolatedExcept.cpp
	g++ -c PrecondViolatedExcept.cpp

clean:
	rm -f *.o PA05
