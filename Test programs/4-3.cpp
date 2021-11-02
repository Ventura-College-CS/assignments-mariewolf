#include <iostream>
#include <cstdlib>
#include <ctime>

//selection sort

void makeArray(int [], int);
void printArray(int [], int);
void selectionSort(int [], int);


int main() {
    const int N = 10;
    int arr[N];

    srand(time(0));
    makeArray(arr, N);
    printf("Initial array: ");
    printArray(arr, N);

    selectionSort(arr, N);
    printf("\nSorted array: ");
    printArray(arr, N);

    return 0;
}

void makeArray(int arr[], int N) {
    for (int i=0; i<N; i++) arr[i] = rand() % 100 + 1;
}

void printArray(int arr[], int N) {
    for (int i=0; i<N; i++) printf("%d\t", arr[i]);
}

void selectionSort(int arr[], int N) {
    for (int i=0; i<N; i++) {
        int tempNum = -1;
        int x=i;
        for (int j=i; j<N; j++) {
            if (arr[x] > arr[j]) {tempNum = j; x = j;}
        }
        if (tempNum != -1) std::swap(arr[i], arr[tempNum]);
    }
}