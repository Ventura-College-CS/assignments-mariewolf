#include <iostream>
using namespace std;

int f(int n) {
    if (n<=1) return 1; //base case
    else return n*f(n-1);
}

int GCD(int x, int y) {
    if (x%y == 0) return y; //base case (termination condition)
    else return GCD(y, x%y); //general case
}

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

int binarySearch(int arr[], int first, int last, int target) {
    int ret;
    if (first > last)
        return -1;
    int mid = (first+last)/2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        ret = binarySearch(arr, first, mid-1, target);
    else
        ret = binarySearch(arr, mid+1, last, target);
    return ret;
}

int main() {
    int factorial;
    factorial = f(4);
    cout << factorial << endl;

    int num = GCD(20,25);
    cout << num << endl;

    int fibonacci = fibo(10);
    cout << fibonacci << endl;

    int arr[10] = {5,10,15,20,25,30,35,40,45,50};
    int binSearch = binarySearch(arr, 0, 9, 15);
    cout << "Found in spot: " << binSearch << endl;
}