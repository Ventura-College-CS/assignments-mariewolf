#include "final1.hpp"
#include <fstream>
#include <time.h>
const int N = 10; //number of courses

void makeArray(Course []);
void printArray(Course []);
void qsort(Course [], int, int);
int partition(Course [], int, int);

//mostly copied from question 1

int main() {
    Course arr[N];
    makeArray(arr);
    printArray(arr);

    srand(time(NULL));
    int target = (arr[rand() % N]).getID(); //randomly choose pivot
    cout << "\nPivot: " << target << endl;

    qsort(arr, 0, N-1);
    printArray(arr);
    return 0;
}

void makeArray(Course arr[]) {
    ifstream inFile("courses.txt");
    if (inFile.fail()) {cerr << "File open error\n"; exit(0);} //file check
    int id, cr;
    string nm;

    for (int i=0; i<N; i++) { //read file and fill array
        inFile >> id >> nm >> cr;
        arr[i] = Course(id, nm, cr);
        if (inFile.fail()) {cerr << "File read error\n"; exit(0);} //file check
    }
    inFile.close();
}

void printArray(Course arr[]) {
    cout << "Printing course array...\nID\tNAME\t\tCREDIT\n";
    for (int i=0; i<N; i++)
        cout << arr[i].getID() << "\t" << arr[i].getName() << "\t" << arr[i].getCredit() << endl; //using 'get' functions to print
}

void qsort(Course arr[], int first, int last) {
    int pivot_index;
    if (first>=last) return;
    pivot_index = partition(arr, first, last); //partition array around the pivot
    qsort(arr, first, pivot_index-1);
    qsort(arr, pivot_index+1, last);
}

int partition(Course arr[], int first, int last) {
    int pivot = arr[last].getID(); //last element is the "pivot"
    int i = -1;
    for (int j=0; j<last; j++) {
        if (arr[j].getID() < pivot) //if an element's ID is less than "pivot", increment i and swap element at j with element at i
            swap(arr[++i], arr[j]);
    }
    swap(arr[i+1], arr[last]); //once all elements have been examined, swap pivot with element at i+1
    return i+1; //return pivot index
}