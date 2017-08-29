#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"


using namespace std;

int main() 
try{
  /* implement user menu */
	//============ test for LinkedStack(string)=======================
	cout << "Test for LinkedStack(string)" << endl;
	LinkedStack<string> sstack;
	//===== push() =====
	
	string s1("O");
	sstack.push(s1);
	string s2("RR");
	sstack.push(s2);
	string s3("AAA");
	sstack.push(s3);
	string s4("NNNN");
	sstack.push(s4);
	string s5("GGG");
	sstack.push(s5);
	string s6("ABCDE");
	sstack.push(s6);
	//====== << operator=====
	cout << "stack = " << sstack << endl;
	// ===== top ========
	cout << "top of stack = " << sstack.top() << endl << endl;
	
	
	//===== pop() =====
	cout << "pop every elements one by one from the stack:" << endl;
	while (!sstack.isEmpty()) {
		cout << sstack.pop() << endl;
	}
	cout << "After popping all elements from stack, stack = ";
	cout << sstack << endl;


	//============ test for LinkedQueue(string)=======================
	cout << "Test for LinkedQueue(string)" << endl;
	LinkedQueue<string> squeue;
	  //===== enqueue() =====

	  string s7("1");
	  squeue.enqueue(s7);
	  string s8("22");
	  squeue.enqueue(s8);
	  string s9("333");
	  squeue.enqueue(s9);
	  string s10("4444");
	  squeue.enqueue(s10);
	  string s11("55555");
	  squeue.enqueue(s11);
	  string s12("123456");
	  squeue.enqueue(s12);

	  //====== << operator=====
	  cout << "queue = " << squeue << endl;

	  // ===== first ========
	  cout << "first of queue = " << squeue.first() << endl << endl;
	   
	  //===== dequeue() =====
	  cout << "dequeue every elements one by one from the queue:" << endl; 
	  while (!squeue.isEmpty()) {
	    cout << squeue.dequeue() << endl;
	  }   

	  cout << "After dequeueing all elements from queue, queue = ";
	  cout << squeue << endl;
	 
	 //============ test for LinkedStack(double)=======================
	cout << "Test for LinkedStack(double)" << endl;
	LinkedStack<double> dstack;
	//===== push() =====
	
	double d1(0.8);
	dstack.push(d1);
	double d2(1.0);
	dstack.push(d2);
	double d3(1.2);
	dstack.push(d3);
	double d4(1.9);
	dstack.push(d4);
	
	//====== << operator=====
	cout << "stack = " << dstack << endl;
	// ===== top ========
	cout << "top of stack = " << dstack.top() << endl << endl;
	
	
	//===== pop() =====
	cout << "pop every elements one by one from the stack:" << endl;
	while (!dstack.isEmpty()) {
		cout << dstack.pop() << endl;
	}
	cout << "After popping all elements from stack, stack = ";
	cout << dstack << endl;


	//============ test for LinkedQueue(double)=======================
	cout << "Test for LinkedQueue(double)" << endl;
	LinkedQueue<double> dqueue;
	  //===== enqueue() =====

	double d5(0.8);
	dqueue.enqueue(d5);
	double d6(1.0);
	dqueue.enqueue(d6);
	double d7(1.2);
	dqueue.enqueue(d7);
	double d8(1.9);
	dqueue.enqueue(d8);

	  //====== << operator=====
	  cout << "queue = " << dqueue << endl;

	  // ===== first ========
	  cout << "first of queue = " << dqueue.first() << endl << endl;
	   
	  //===== dequeue() =====
	  cout << "dequeue every elements one by one from the queue:" << endl; 
	  while (!dqueue.isEmpty()) {
	    cout << dqueue.dequeue() << endl;
	  }   

	  cout << "After dequeueing all elements from queue, queue = ";
	  cout << dqueue << endl;
	 

	 //============ test for Parser=======================
	 cout << "Test for Parser" << endl; 
	Parser test("a+(6/b)#");
    test.printInfix();
    test.printPostfix();
    cout << endl;

	 //============ test for Evalutor=======================
	cout << "Test for Evaluator" << endl; 
    Evaluator test2(test);
    test2.usersValue();
    cout << " The associative value for this expression is:" << endl;
    cout << test2.getValue() << endl;

    //=============basic menu for user==========================

    // 1. Read an infix expression from the keyboard
    cout << "Please input an infix expression from keyboard:" << endl;
    string infix;
    cin >> infix;


    // 2.Display a correct infix expression on the screen or a message to inform that parantheses 
    // are not balanced or there is an invalid input in this string
     Parser P(infix);
     cout << "Infix expression is:" << endl;
     P.printInfix();

     // 3. Convert infix form to its postfix form and display a postfix queue on the screen
     cout << " Convert to its postfix expression is:" << endl;
     P.printPostfix();
     cout << endl;

     // 4.Evaluate postfix form of the expression for floating point values entered from the keyboard
     Evaluator E(P);

     // 5.Display the value of an algebraic expression on the screen
     E.usersValue();
     cout << " The associative value for this expression is:" << endl;
     cout << E.getValue() << endl;
	
}
  catch(int) {// catch invalid input
    cerr << " Invaild input!!!" << endl;
  }
  catch(char){// catch unbalanced parenthese error
  	cerr << "Unbalanced parantheses!!!" << endl;
  }
  catch(RuntimeException& e)
  {
  	cerr << e << endl;
  }
  catch(...) {// catch other errors
    cerr << "Uncaught error: " << endl;
  }
