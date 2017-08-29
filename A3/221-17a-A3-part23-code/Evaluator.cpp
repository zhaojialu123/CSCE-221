#include "Evaluator.h"


using namespace std;

//get the letters' values from users
void Evaluator::usersValue()
{
	vector<string> temp;
	while(!helper.isEmpty())
		temp.push_back(helper.dequeue());
	for(int i = 0; i < temp.size()/2; i++)
		 {
		 	if(temp[i][0] >= 'a' && temp[i][0] <= 'z')
		 	{
		 		cout << "please input the value of " << temp[i][0] << ":" << endl;
		 		int value;
		 		cin >> value;
		 		temp[i] = to_string(value);
		 	}
		 }
	for(int i = 0;i < temp.size()/2; i++)
		postfix.enqueue(temp[i]);
	 
}

double Evaluator::getValue() {
  /* returns the result of expression evaluation */
	double result;
	while(!postfix.isEmpty())
	{
		if(postfix.first()[0] >= '0' && postfix.first()[0] <= '9')
		{
			int sum = 0;
			for( int i = 0;i < (postfix.first()).size();i++)
				sum = sum + ((postfix.first())[i]-'0') * pow(10,(postfix.first()).size()-i-1);
				valStack.push(sum);
		}
		else if(postfix.first() == "+")
			{
				result = valStack.pop() + valStack.pop();
				valStack.push(result);
			}
		else if(postfix.first() == "-")
			{
				result = 0-(valStack.pop() - valStack.pop());
				valStack.push(result);
			}
		else if(postfix.first() == "*")
			{
				result = valStack.pop() * valStack.pop();
				valStack.push(result);
			}
		else if(postfix.first() == "/")
			{
				result = 1/(valStack.pop() / valStack.pop());
				valStack.push(result);
			}
		else if(postfix.first() == "^")
			{
				double a = (int)valStack.pop(); 
				double b = (int)valStack.pop();
				result = pow(b,a);
				valStack.push(result);
			}
			postfix.dequeue();
	}
	return valStack.top();
} 
/*int main()
{
    Parser test("a+99#");
    test.printInfix();
    test.printPostfix();
    Evaluator test2(test);
    cout << test2.getValue() << endl;
	
}*/
