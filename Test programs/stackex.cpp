#include <iostream>
#include "genStack.h"
using namespace std;

int isOperator(char);
int precedence(char);

int main()
{
	string infix = "a+b*c+d";
	Stack<char, 10> stack;

	for (int i = 0; i < infix.size(); i++) //for all tokens in an expression
	{
		if (!isOperator(infix[i])) //if it's not an operator
		{
			cout << infix[i] << " "; //print operand
			continue;
		}
		else
			while ((!stack.isEmpty()) && (precedence(infix[i]) <= precedence(stack.topEl())))
				cout << stack.pop() << " "; //while stack not empty & current [i] has less precedence than topmost element in stack, print and remove (pop) topmost element
		stack.push(infix[i]); //place current el [i] at top of stack
	}
	while (!stack.isEmpty())
		cout << stack.pop() << " "; //print & pop remaining elements in stack
	cout << endl;
}

int precedence(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 5;
	case '*':
	case '/':
		return 10;
	default:
		cout << "Undefined Operator \n";
		exit(0);
	}
}

int isOperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}