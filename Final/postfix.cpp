#include "postfix.hpp"
#include <stack>
//mostly copied from previous assignment (5-2)

int Postfix::isOperator(char op) {
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

int Postfix::calculate(int op1, int op2, char opr) {
	int result;
	switch (opr)
	{
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	default:
		cout << "Undefined operator error\n";
		exit(0);
	}
	return result;
}

int Postfix::evaluation() {
    const int N = 20;
	const int offset = 48;
	stack<int> cStack;
	char input;
	int opr1, opr2, result;

	for (int i = 0; i < expression.size(); i++) {
		input = expression[i];
		if (isdigit(input))
			cStack.push(int(input) - offset);
		else if (isOperator(input)) {
			opr2 = cStack.top(); cStack.pop();
            opr1 = cStack.top(); cStack.pop();
			result = calculate(opr1, opr2, input);
			cStack.push(result);
		}
	}
    return cStack.top();
}
