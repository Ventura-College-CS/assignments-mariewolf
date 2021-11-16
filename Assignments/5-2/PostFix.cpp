#include "PostFix.h"
#include "genStack.h"
using namespace std;

int PostfixExp::isOperator(char op) {
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

int PostfixExp::calculate(int op1, int op2, char opr) {
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

PostfixExp::PostfixExp() {
	//do nothing
}

PostfixExp::PostfixExp(string in) {
    expression = in;
}

void PostfixExp::setExpression(string in) {
    expression = in;
}

void PostfixExp::printExpression() const {
    cout << "The expression is: " << expression << "\n";
}

int PostfixExp::Evaluation() {
    const int N = 20;
	const int offset = 48;
	Stack<int, N> stack;
	char input;
	int opr1, opr2, result;

	for (int i = 0; i < expression.size(); i++) {
		input = expression[i];
		if (isdigit(input))
			stack.push(int(input) - offset);
		else if (isOperator(input)) {
			opr1 = stack.pop();
			opr2 = stack.pop();
			result = calculate(opr1, opr2, input);
			stack.push(result);
		}
	}
    return stack.pop();
}
