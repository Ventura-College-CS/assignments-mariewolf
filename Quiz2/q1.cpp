#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillupArray(double *, int N);
void printArray(double *, int N);


int main() {
    const int N = 10;
    double *ptr = new double[N];
    fillupArray(ptr, N);
    cout << "Array: ";
    printArray(ptr, N);

    return 0;
}

void fillupArray(double *ptr, int N) {

    srand(time(0));
    for(int i=0; i<N; i++) {
        *(ptr+i) = (rand() % 100);
    }
}

void printArray(double *ptr, int N) {
    for (int i=0; i<N; i++)
        cout << *(ptr+i) << " ";
    cout << endl;
}