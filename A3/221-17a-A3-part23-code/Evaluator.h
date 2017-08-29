#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
//#include "Parser.cpp"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"
#include <math.h> 

class Evaluator {
public:
  // user-defined exceptions
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };     
private:
  /* declare member variables; 
    may include a string postfix queue and a double value stack */
  LinkedStack<double> valStack;
  LinkedQueue<string> helper;
  LinkedQueue<string> postfix;
  /* declare utility functions */

public:
  Evaluator(Parser& par) 
  { 
    helper = par.ToPostfix();
  } // constructor
  void usersValue(); //get the letters' value from users 
  double getValue(); // returns the result of expression evaluation
};

#endif
