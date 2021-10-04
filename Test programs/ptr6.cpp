#include <iostream>
using namespace std;

void myfunction();

int main() {
    char *ptr;

    char name[10];
    ptr = name; //assign array to ptr address
    cout << "Enter your name: \n";
    cin >> ptr;


    int *iptr;
    //option 1: iptr = new int;
    //option 2: normal variable's address [ex: iptr = &i;]
    cin >> *iptr; //causes error b/c there's no space to save the int. no space the pointer is pointing to
}