#include "Parser.h"

using namespace std;

//default constructor
Parser::Parser(string s): opStack (),expQueue (),IF(s),infix() {}

//destructor
Parser::~Parser()
{
    opStack.~LinkedStack();
    expQueue.~LinkedQueue();
}
// get token one by one from a string 

// function to judge if parantheses are balanced
bool Parser::ParanthesesBalanced()
{
    LinkedStack<char> PB;
    for(int i = 0;i < IF.size(); i++)
    {
        if(IF[i] == '(')
        {
            PB.push(IF[i]);
        }

        else if(IF[i] == ')')
            {
                PB.pop();
           } 
    }    
        return PB.isEmpty();

}

// function to judge if there is an invaild input
bool Parser::InvaildInput()
{
    int count = 0;
    for (int i = 0;i < IF.size(); i++){
        if(IF[i] == '+'||IF[i] == '-'||IF[i] == '*'||IF[i] == '/'||IF[i] == '^'||IF[i] == '#'||IF[i] == '('||IF[i] == ')')
            count++;
        else if(IF[i] >= 'a' && IF[i] <= 'z')
            count++;
        else if(IF[i] >= '0' && IF[i] <= '9')
            count++;
    }
    return (count != IF.size());
}

void Parser::getToken()
{  
    string helper = "";
    for(int i = 0; i < IF.size(); i++)
    {
        if(isdigit(IF[i]))
            helper = helper + IF[i];
        else
        {
            infix.push_back(helper);
            helper = "";
            string temp = "";
            temp = temp + IF[i];
            infix.push_back(temp);
        }

    }
}
LinkedQueue<string> Parser::ToPostfix()
{
    opStack.push("#"); //push END token
	for(int i = 0;i < infix.size(); i++)
    {
		// if the token is an operand, enqueue it to expQueue.
		if (IsOperand(infix[i]))
			expQueue.enqueue(infix[i]);
        //if the token is RPAREN, pop entries from opStack and
        //enqueue them on postfix until a matching LPAREN is
        //popped. Discard both left and right parentheses.
		else if (infix[i] == ")"){
			while(opStack.top() != "(")
                    expQueue.enqueue(opStack.pop());
                opStack.pop();
        }
		//if the token is the END token, pop all entries that remain on
        //opStack and enqueue them on postfix.
        else if (infix[i] == "#")
        {
        	while (opStack.top() != "#")
        		expQueue.enqueue(opStack.pop());
        }
        // if the token is LPAREN, push it on opStack.
        else if (infix[i] == "(")
        {
            opStack.push("(");
        }
        //otherwise the token is an operator, therefore pop from
        //opStack and enqueue on the postfix queue those
        //operators whose stack priority is greater than or equal to
        //the input priority of the current operator (corresponding to
        //the current token). After popping these operators, the
        //current token is pushed on the stack.
        else if(IsOperator(infix[i])) // an operator is encountered
        {
        	while(HasHigherPrecedence(stackPriority(opStack.top()),inputPriority(infix[i])))
        		expQueue.enqueue(opStack.pop());
        	opStack.push(infix[i]);
        }
    }
    //repeat the previous steps until the token is equal to END
    while(opStack.top() != "#")
        expQueue.enqueue(opStack.pop());
    return expQueue;
}



// function to verify whether a charcter is an operand or not
bool Parser::IsOperand(string s)
{
    if (s != "+" && s != "-" && s != "*" && s != "/" && s!= "^"&& s!= "("&& s!= ")"&& s!= "#")
        return true;
    else
        return false;

}

//function to verify whether a character is an operator or not
bool Parser::IsOperator(string s)
{
    if (s == "+" ||s == "-" ||s == "*" ||s == "/" ||s == "^")
        return true;
    else
        return false;
}

//function to get the input priority of an operator
int Parser::inputPriority(string op)
{
	int Ip;
    if(op == "(")
        Ip = 100;
    else if(op == ")")
        Ip = 0;
    else if(op == "+" || op == "-")
        Ip = 1;
    else if(op == "*" || op == "/")
        Ip = 3;
    else if(op == "^")
        Ip = 6;
    else if(op == "#")
        Ip = 0;

    return Ip;
}
//function to get the stack priority of an operator
int Parser::stackPriority(string op)
{
    int Sp;
    if(op == "(")
        Sp = 0;
    else if(op == ")")
        Sp = 99;
    else if(op == "+" || op == "-")
        Sp = 2;
    else if(op == "*" || op == "/")
        Sp = 4;
    else if(op == "^")
        Sp = 5;
    else if(op == "#")
        Sp = -1;
    
    
    return Sp;
}
// function to perform an operation and return ouput
int Parser::HasHigherPrecedence(int op1Weight, int op2Weight)
{
	if(op1Weight >= op2Weight)
     return true;
    else 
      return false;
}

void Parser::printInfix() 
{
    if(!ParanthesesBalanced())
        throw 'a';
    if(InvaildInput())
        throw 20;
    getToken();
    cout << '{';
    for(int i = 0;i < infix.size()-1; i++)
        cout << infix[i];
    cout << '}';
    cout << endl;

}

void Parser::printPostfix() 
{
    cout << ToPostfix();
}


/*
int main()
{
    Parser test("a+99*89+89#");
    test.printInfix();
    test.printPostfix();
	
}*/



/* initialize constants here */

/* describe rest of functions */
