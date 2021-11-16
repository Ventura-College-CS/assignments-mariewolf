#include "PostFix.h"
#include "Postfix.cpp"
#include <iostream>
using namespace std;

int main() {
    PostfixExp a;
    a.setExpression("243*+5+");
    cout << "The result is: " << a.Evaluation() << "\n";
    a.printExpression();
}