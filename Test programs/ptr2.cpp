#include <iostream>
using namespace std;

int main() {
    int num[5] = {5, 10, 15, 20, 25}; //unit space for an element: 4 bytes

    double d[5] = {1.0, 2.0, 3.0, 4.0, 5.0}; //8 bytes

    int *ptr;

    double *dptr;

    ptr = num; //gives address of num array. Array is a kind of constant pointer.

    cout << *ptr << endl; //output: 5
    cout << *(ptr+4) << endl; //output: 25

    dptr = d;
    cout << *(dptr+2) << endl; //output: 3
}