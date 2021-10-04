#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    double numbers[N] = {10.0, 15.2, 21.2, 10.5, 11.3, 12.5, 13.8, 14.7, 19.8, 20.0};
    double *ptr;

    ptr = numbers;

    cout << "\nPrinted array with pointer arithmetic: \n";
    for (int i=0; i<N; i++)
        cout << *(ptr+i) << "\t"; //prints by memory address, incremented by i*sizeof(double). The arithmetic expression pointing to the ith element is *(ptr+i)
    cout << endl << "Address of first element (using ptr): " << ptr << endl; //ptr has the memory address of numbers (and the first element)
    cout << "Address of numbers: " << &numbers << endl; //to show they are the same
    return 0;
}