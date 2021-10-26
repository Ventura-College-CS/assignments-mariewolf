#include <iostream>
#include <time.h>
using namespace std;

void makeArray(int array[], int N);
int linearSearch(int array[], int N, int target);
int binarySearch(int array[], int N, int target);
void sortArray(int array[], int N);
void printArray(int array[], int N);

int main() {
    const int N = 64;
    int array[N], target;
    int tries = 100;
    int linNumber = 0;
    int binNumber = 0;

    srand(time(NULL));
    makeArray(array, N);
    cout << "Unsorted: "; printArray(array, N);
    sortArray(array, N);
    cout << "\n\nSorted: "; printArray(array, N);
    
    for (int i=0; i<tries; i++) {
        target = array[rand() % N];
        linNumber += linearSearch(array, N, target);
        binNumber += binarySearch(array, N, target);
    }

    cout << "\n\nAverage amount of comparisons (linear search): " << linNumber/tries << endl;
    cout << "Average amount of comparisons (binary search): " << binNumber/tries << endl; 

    return 0;
}

void makeArray(int array[], int N) {
    for (int i=0; i<N; i++) array[i] = rand() % 100 + 1;
}

int linearSearch(int array[], int N, int target) {
    int comp = 0;
    for (int i=0; i<N; i++) {
        comp ++;
        if (array[i] == target) return comp;
    }
    return comp;
}

int binarySearch(int array[], int N, int target) {
    int first, last, mid, comp;

    first = comp = 0;
    last = N-1;

    while(first <= last) {
        comp ++;
        int mid = (first+last)/2;
        if (array[mid] == target) return comp;
        else if (array[mid] < target) first = mid + 1;
        else last = mid - 1;
    }
    return comp;
}

void sortArray(int array[], int N) {
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (array[i] > array[j]) swap(array[i], array[j]);
        }
    }
}

void printArray(int array[], int N) {
    for (int i=0; i<N; i++) cout << array[i] << "\t";
}
