#include <iostream>
#include "genStack.h"
using namespace std;

int isOperator(char);
int precedence(char);

int main() {
    string infix = "a+b*(c+d*e+f)";
    Stack<char, 13> tStack; //20

    for (int i=0; i<infix.size(); i++) {
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            cout << infix[i];
        }
        if (infix[i] == '(') {
            tStack.push(infix[i]);
            continue;
        }
        if (isOperator(infix[i])) {
            if (!tStack.isEmpty() && tStack.topEl() != '(' && precedence(infix[i]) <= precedence(tStack.topEl())) {
                while (tStack.topEl() != '(')
                    cout << tStack.pop();
            }
            else tStack.push(infix[i]);
        }
        if (infix[i] == ')') {
            while (tStack.topEl() != '(' || !tStack.isEmpty())
                tStack.pop();
        }
    }
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