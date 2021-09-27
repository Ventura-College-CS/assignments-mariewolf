#include <iostream>
#include <fstream>
using namespace std;

const int NUM = 10;

struct Student {
    int sID, score1, score2;
    char sName[20];
} rookies[NUM];

int findStudent(int);

int main() {

    int searchID, f;

    cout << "Enter an ID to search for that students' records: ";
    cin >> searchID;
    
    ifstream sBin("student.bin", ios::in | ios::binary);
    for (int i = 0; i<NUM; i++) {
		sBin.read((char *)&rookies[i], sizeof(rookies[i]));
    }

    if ((f = findStudent(searchID)) != -1) {
        cout << "\nFound on line " << f+1 << "." << endl;
        cout << "\nID #: " << rookies[f].sID << "\nName: " << rookies[f].sName;
        cout << "\nScore 1: " << rookies[f].score1 << "\nScore 2: " << rookies[f].score2;
        cout << "\nAverage: " << (rookies[f].score1+rookies[f].score2)/2.0 << endl; }

    else cout << "Student not found." << endl;
    sBin.close();

    return 0;
}

int findStudent(int N) {
    int flag = -1;
	for (int i = 0; i<NUM; i++) {
        if (rookies[i].sID == N) flag = i;
    }
    return flag;
}