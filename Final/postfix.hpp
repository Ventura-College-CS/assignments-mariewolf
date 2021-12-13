#ifndef POSTFIX_HPP
#define POSTFIX_HPP
#include <iostream>
using namespace std;

class Postfix {
    private:
        string expression;
        int isOperator(char);
        int calculate(int, int, char);
    public:
        Postfix() : expression(0) {}
        Postfix(string ex) : expression(ex) {}
        int evaluation();
};

#endif