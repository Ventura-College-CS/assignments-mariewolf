#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    double numbers[N] = {10.0, 15.2, 21.2, 10.5, 11.3, 12.5, 13.8, 14.7, 19.8, 20.0};
    double *ptr;

    ptr = numbers;

    cout << "Printed array with pointer treated as array notation: \n";
    for (int i=0; i<N; i++)
        cout << ptr[i] << " ";
    cout << "\nPrinted array with pointer arithmetic: \n";
    for (int i=0; i<N; i++)
        cout << *(numbers+i) << " ";
    cout << endl << "Address of first element: " << &ptr << endl;

    return 0;
}