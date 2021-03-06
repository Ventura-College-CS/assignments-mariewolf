#include "final1.hpp"
#include <fstream>
#include <time.h>

const int N = 10; //number of courses

void makeArray(Course []);
void printArray(Course []);
int binarySearch(Course [], int);

int main() {
    Course arr[N];
    makeArray(arr);
    printArray(arr);

    srand(time(NULL));
    int target = (arr[rand() % N]).getID(); //randomly choose target
    cout << "\nTarget: " << target << endl;

    int retIndex = binarySearch(arr, target);
    if (retIndex == -1) {cerr << "Target not found\n"; exit(0);}
    else
        cout << "Target found! Located at index " << retIndex << ", which is course " << arr[retIndex].getName() << endl; 

    return 0;
}

void makeArray(Course arr[]) {
    ifstream inFile("courses.txt"); //I created my own courses file; hope that's okay!
    if (inFile.fail()) {cerr << "File open error\n"; exit(0);} //file check
    int id, cr;
    string nm;

    for (int i=0; i<N; i++) { //read file and fill array
        inFile >> id >> nm >> cr;
        arr[i] = Course(id, nm, cr);
        if (inFile.fail()) {cerr << "File read error\n"; exit(0);} //file check
    }
    inFile.close();

    for (int i=0; i<N-1; i++) { //sort array
        for (int j=i+1; j<N; j++)
            if (arr[i].getID() > arr[j].getID()) swap(arr[i], arr[j]);
    }
}

void printArray(Course arr[]) {
    cout << "Printing course array...\nID\tNAME\t\tCREDIT\n";
    for (int i=0; i<N; i++)
        cout << arr[i].getID() << "\t" << arr[i].getName() << "\t" << arr[i].getCredit() << endl; //using 'get' functions to print
}

int binarySearch(Course arr[], int target) {
    int first, last, mid;
    first = 0;
    last = N-1;

    while (first <= last) {
        int mid = (first+last)/2;
        if (arr[mid].getID() == target) return mid;
        else if (arr[mid].getID() < target) first = mid + 1;
        else last = mid - 1;
    }
    return -1;
}