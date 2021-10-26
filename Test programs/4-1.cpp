#include <iostream>
using namespace std;

int binarySearch(int array[], int N, int target); //returns found index

int main() {
    const int N = 10;
    int target;
    int arr[N] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55};

    cout << "Enter a value to search for: ";
    cin >> target;

    int found = binarySearch(arr, N, target);
    cout << "Match found at index: " << found << endl;
}

int binarySearch (int arr[], int N, int target) {
    int first = 0;
    int last = N - 1;
    while(first <= last) {
        int mid = (first+last)/2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) first = mid + 1;
        if (arr[mid] > target) last = mid - 1;
    }
    return -1;
}