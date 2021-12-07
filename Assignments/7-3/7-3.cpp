#include <iostream>
#include <time.h>
using namespace std;

int binarySearch(int arr[], int first, int last, int target) {
    int ret;
    if (first > last) return -1;
    int mid = (first+last)/2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target)
        ret = binarySearch(arr, first, mid-1, target);
    else
        ret = binarySearch(arr, mid+1, last, target);
    return ret;
}

void createArray(int arr[], int N) {
    srand(time(NULL));
    for (int i=0; i<N; i++) arr[i] = rand() % 100 + 1;

    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++)
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
    }
}

int main() {
    const int N = 10;
    int target, arr[N];
    createArray(arr, N);

    cout << "Array: ";
    for (int i=0; i<N; i++) cout << arr[i] << " ";

    cout << "\nEnter the target value: ";
    cin >> target; //target value can also be randomized using target = array[rand() % N];

    int indexNum = binarySearch(arr, 0, (N-1), target);
    if (indexNum==-1)
        cout << "Not found.\n\n";
    else
        cout << "Found at index number " << indexNum << ", which is " << arr[indexNum] << "\n\n";

    int txt[] = {84,104,97,110,107,32,121,111,117,32,102,111,114,32,116,104,101,32,103,114,101,97,116,32,99,108,97,115,115,32,40,58};
    for (int i=0; i<32; i++)
        cout << static_cast<char>(txt[i]);

    return 0;
}