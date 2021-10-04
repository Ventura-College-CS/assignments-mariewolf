#include <iostream>
using namespace std;

int main() {
    int     num1=100;
    int     num2=200;

    int *ptr1;

    cout << &num1 << endl; //memory address of num1
    cout << &num2 << endl; //memory address of num2

    ptr1 = &num1; //pointer var has the address of other var

    cout << ptr1 << endl; //9e48 [same address as num1]
    cout << *ptr1 << endl; //100 [indirect (dereferenced) value]

    ptr1 = &num2;
    cout << *ptr1 << endl; // 200 [indirect (dereferenced) value]

    int *ptr2;
    ptr2 = ptr1; //assign the direct value (address) of ptr1 to ptr2. ptr2 = address of num2
}