#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double *makeNumbers(int N);
void printNumbers(double *, int N);
void sortNumbers(double *, int N);

int main() {
    const int N = 10;
    double *ptr;

    ptr = makeNumbers(N);
    printNumbers(ptr, N);
    sortNumbers(ptr, N);
    printNumbers(ptr, N);

}

double *makeNumbers(int N) {
    double *ptr;
    ptr = new double[N];

    srand(time(0));
    for(int i=0; i<N; i++) {
        *(ptr+i) = rand() % 100; //generate random numbers
    }

    return ptr;
}

void printNumbers(double *ptr, int N) {
    for (int i=0; i<N; i++)
        cout << *(ptr+i) << "\t";
    cout << endl;
}

void sortNumbers(double *ptr, int N) {
    int tempHolder;
    for (int i = 0; i < 5; i++) {
        tempHolder = *(ptr+i);
        *(ptr+i) = *(ptr+N-i-1);
        *(ptr+N-i-1) = tempHolder;
    }
}