#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int sID, score1, score2, score3;
    char sName[20];
};

int main() {
    const int NUM = 10;
    Student *ptr = new Student[NUM];
    ofstream sBin("student.bin", ios::out| ios::binary);
    ifstream sFile("students.txt");
    if (!sBin || !sFile) {
        cout << "File error!" << endl;
        return 1; }
    
    for (int i=0; i<NUM; i++) {
        sFile >> ptr[i].sID >> ptr[i].sName >> ptr[i].score1 >> ptr[i].score2 >> ptr[i].score3;
        sBin.write( (char*)&ptr[i], sizeof(ptr[i])); }
    
    sBin.close();
    sFile.close();

    cout << "Task was successful." << endl;

    return 0;
}
