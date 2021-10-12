#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int sID, score1, score2, score3;
    char sName[20];
} ;

int findStudent(int);

int main() {

    const int NUM = 10;
    Student *ptr = new Student[NUM];

    ifstream sBin("student.bin", ios::in | ios::binary);
    for (int i = 0; i<NUM; i++) {
		sBin.read((char *)&ptr[i], sizeof(ptr[i]));
    }

    for (int i = 0; i < NUM; i++) {
        int average = (ptr[i].score1+ptr[i].score2+ptr[i].score3)/3.0;
        if (average > 85) {
            cout << "ID #: " << ptr[i].sID << "\tName: " << ptr[i].sName;
            cout << "\tScore 1: " << ptr[i].score1 << "\tScore 2: " << ptr[i].score2;
            cout << "\tScore 3: " << ptr[i].score3 << "\tAverage: " << average << endl; }
    }
    sBin.close();

    return 0;
}