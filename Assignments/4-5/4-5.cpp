#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//code modified from https://github.com/Kwooley/CS-V15/blob/main/module4/vector3.cpp

void initVectors(vector<int> &, vector<string> &, int);
void printVectors(vector<int>, vector<string>, int);
void sortVectors(vector<int> &, vector<string> &, int);

int main() {
    const int N = 10;
    vector<int> IDs(N);
    vector<string> names(N);

    initVectors(IDs, names, N);
    printVectors(IDs, names, N);
    sortVectors(IDs, names, N);
    printVectors(IDs, names, N);

    return 0;
}

void initVectors(vector<int> &IDs, vector<string> &names, int N) {
    //opens text file & writes the info to vectors 'IDs' and 'names'
    ifstream studentBin("students.txt");
    if (!studentBin) {cout << "File open error!"; exit(0);}

    for (int i=0; i<N; i++) {
        studentBin >> IDs[i] >> names[i];
        if (studentBin.fail()) {cout << "File read error!"; exit(0);}
    }
    studentBin.close();
}

void sortVectors(vector<int> &IDs, vector<string> &names, int N) {
    //sorts vector 'IDs' by student ID number and modifies vector 'names' accordingly
    int minval, minid;
    string temp;
    for (int i=0; i<N; i++) {
        minval = IDs[i]; //ID to be compared is loaded into 'minval'
        minid = i;
        for (int j=i+1; j<N; j++) {
            if (minval > IDs[j]) {minval = IDs[j]; minid = j;} //IDs after index value 'i' are compared to minval, and, if found to be less, this value is the new "minimum"
        }
        IDs[minid] = IDs[i]; //vector 'IDs' is modified so that the current "minimum" ID is now equal to what it was compared with
        IDs[i] = minval; //the compared ID is set to equal the found "minimum" ID (these two lines essentially swap the IDs)

        temp = names[minid];
        names[minid] = names[i];
        names[i] = temp; //values in the 'names' vector are swapped accordingly
    }
}

void printVectors(vector<int> IDs, vector<string> names, int N) {
    //prints the passed vectors
    for (int i=0; i<N; i++)
        cout << IDs[i] << "\t" << names[i] << "\n";
    cout << endl;
}