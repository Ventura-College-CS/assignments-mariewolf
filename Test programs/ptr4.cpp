#include <iostream>
using namespace std;

struct Students{
    int id;
    char name[10];
};

int main() {
    int     *ptr;
    int     num=100;

    Students s;
    Students *sptr;
    sptr = new Students; //2 fields, int & char[10] = 14 bytes of memory space
    sptr->id = 10; //same as "s.id = 10;" or "(*sptr).id = 10;"

    ptr = &num; //basic use of pointer var
    cout << *ptr << endl; // 100

    ptr = new int; // points to new memory space (4 bytes)
    *ptr = 200;
    cout << *ptr << endl; //garbage value -> 200

    ptr = new int[10]; //allocate 10x4 bytes = continuous 40 bytes

    *ptr = 10;
    *(ptr+4) = 20; //memory address ex: 1000 + (4x4) = 1016
    *(ptr+8) = 30; //ex: 1000 + (8x[unit size: 4]) = 1032

    for (int i=0; i<10; i++) {
        cout << *(ptr+i) << endl;
    } 
    cout << endl;
}