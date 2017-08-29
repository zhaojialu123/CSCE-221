all: run-main

run-main: Parser.o Evaluator.o Main.o
	c++ -std=c++11 Parser.o Evaluator.o Main.o -o main

Main.o: Parser.h Evaluator.h RuntimeException.h
	c++ -std=c++11 -c Main.cpp

Evaluator.o: Evaluator.h Parser.h LinkedStack.h LinkedQueue.h TemplatedDoublyLinkedList.h RuntimeException.h
	c++ -std=c++11 -c Evaluator.cpp

Parser.o: Parser.h LinkedStack.h LinkedQueue.h TemplatedDoublyLinkedList.h RuntimeException.h
	c++ -std=c++11 -c Parser.cpp

clean:
	rm -f *.o run-main
