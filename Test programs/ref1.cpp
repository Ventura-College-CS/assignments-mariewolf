#include <iostream>
using namespace std;

void changeValue1(int &);
void changeValue2(int );
void changeValue3(int *);

int main() {
    /*
    int *ptr;
    cout << *ptr << endl; //will get an error. Uninitialized variable leads to segmentation fault [permission error] */

    int num = 100;

    //int &ref; // illegal, ref needs to be initialized
    int &ref = num;

    cout << ref << endl; //100
    
    ref = 200;

    cout << ref << endl; //200
    cout << num << endl; //200

    changeValue1(num);
    cout << num << endl;

    changeValue3(&num);
    cout << num << endl;

}

void changeValue1(int &ref) {
    ref = 500;
}

void changeValue3(int *ref) {
    *ref = 1000;
}