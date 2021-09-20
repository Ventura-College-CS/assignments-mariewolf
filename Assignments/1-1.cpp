#include <iostream>
#include <fstream>
using namespace std;

const int NUM = 10;

struct Student {
    int sID, score1, score2;
    string sName;
} rookies[NUM];

int findStudent(int);

int main() {

    int searchID, f;

    ofstream sBin("student.bin", ios::out | ios::binary);
    ifstream sFile("students.txt");
    if (!sBin || !sFile) {
        cout << "File error!" << endl;
        return 1; }
    
    for (int i=0; i<NUM; i++) {
        sFile >> rookies[i].sID >> rookies[i].sName >> rookies[i].score1 >> rookies[i].score2;
        sBin << rookies[i].sID << rookies[i].sName << rookies[i].score1 << rookies[i].score2; }
    
    sBin.close();
    sFile.close();

    cout << "Enter an ID to search for that students' records: ";
    cin >> searchID;
    
    if (findStudent(searchID) != -1) {
        f = (findStudent(searchID));
        cout << "\nFound on line " << f+1 << "." << endl;
        cout << "\nID #: " << rookies[f].sID << "\nName: " << rookies[f].sName;
        cout << "\nScore 1: " << rookies[f].score1 << "\nScore 2: " << rookies[f].score2;
        cout << "\nAverage: " << (rookies[f].score1+rookies[f].score2)/2.0; }

    else cout << "Student not found." << endl;

    return 0;
}

int findStudent(int N) {
    int flag = -1;
    ifstream sBin("student.bin");
    for (int i = 0; i<NUM; i++) {
        if (rookies[i].sID == N) flag = i;
    }
    return flag;
}