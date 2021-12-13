#include "postfix.cpp"

int main() {
    string ex;
    cout << "Enter an expression: ";
    cin >> ex;
    Postfix toSolve(ex);
    cout << "The result is: " << toSolve.evaluation() << endl;
    return 0;
}