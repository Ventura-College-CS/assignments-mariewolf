#include <iostream>
using namespace std;

int &getValue(void);
int &setValue(void);

int num = 100;

int main() {
    //cout << "Return value is: " << getValue() << endl;
    setValue() = 10;
}
/*
int &getValue() {
    int num = 100;
    return num; //causes error
} */

int &setValue() {
    return num;
}