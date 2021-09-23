#include <iostream>
#include <fstream>
using namespace std;

const int NUM = 10;

struct Student {
    int sID, score1, score2;
    char sName[20];
} rookies[NUM];


int main() {

    int searchID, f;

    ofstream sBin("student.bin", ios::out | ios::binary);
    ifstream sFile("students.txt");
    if (!sBin || !sFile) {
        cout << "File error!" << endl;
        return 1; }
    
    for (int i=0; i<NUM; i++) {
        sFile >> rookies[i].sID >> rookies[i].sName >> rookies[i].score1 >> rookies[i].score2;
        // sBin << rookies[i].sID << rookies[i].sName << rookies[i].score1 << rookies[i].score2; } // this line does not means binary output.
    // Instead of this, sBin.write( (char *)rookies[i], sizeof(rookies[i]);
		sBin.write( (char *)&rookies[i], sizeof(rookies[i])) ;
	}
    
    sBin.close();
    sFile.close();
}
