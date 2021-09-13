#include <iostream>
using namespace std;

int main() {
    bool flag = false;
    int tempHolder = 0;

    const int N = 10;
    int numbers[N] = {5,7,2,4,6,7,10,1,3,9};
    for (int j = 0; j < N; j++) cout << numbers[j] << " ";

    for (int i = 0; i < 5; i++) {
        tempHolder = numbers[i];
        numbers[i] = numbers[N-i-1];
        numbers[N-i-1] = tempHolder;
    }

    cout << "\nThe numbers have been rearranged." << endl;
    for (int j = 0; j < N; j++) cout << numbers[j] << " ";
}