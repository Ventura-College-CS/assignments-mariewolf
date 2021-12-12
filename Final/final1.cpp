#include "final1.hpp"
#include <fstream>
#include <time.h>

const int N = 10; //number of courses

void makeArray(Course []);
int binarySearch(Course []);
void printArray(Course []);

int main() {
    int target;
    Course arr[N];
    makeArray(arr);

    srand(time(NULL));
    int target = (arr[rand() % N]).getID(); //randomly choose target
    cout << "\nTarget: " << target << endl;

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

    for (int i=0; i<N-1; i++) { //sort array
        for (int j=i+1; j<N; j++)
            if (arr[i].getID() > arr[j].getID()) swap(arr[i], arr[j]);
    }
}