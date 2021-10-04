#include <iostream>
using namespace std;

void printArray(int *, int);

int main() {
    int num[5] = {5, 10, 15, 20, 25}; //unit space for an element: 4 bytes

    /*
    for (int i=0; i<5; i++) {
        cout << *(num+i) << "\t";
        cout << num[i] << "\t"; // same as above
    }
    cout << endl;
    */
    printArray(num, 5);
}

void printArray(int *ptr, int n) {
    for (int i=0; i<5; i++) cout << *(ptr+i) << "\t";
    cout << endl;
}