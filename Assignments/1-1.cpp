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
        sBin << rookies[i].sID << rookies[i].sName << rookies[i].score1 << rookies[i].score2; } // this line does not means binary output.
    // Instead of this, sBin.write( (char *)rookies[i], sizeof(rookies[i]);
    
    
    
    sBin.close();
    sFile.close();

    cout << "Enter an ID to search for that students' records: ";
    cin >> searchID;
    
    // The below code is not the search from the binary file.
    // In your code, you were trying to find the certain student in the rookies[i] array directly, not the file
    
    
    if (findStudent(searchID) != -1) {
        f = (findStudent(searchID));

		// no need to call twice. Instead of it, if (f = findStudnet(searchID)) != -1 )



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
	
	// You don't use it after opening it.
	// why do you open the file here? You are supposed to read all lines and save them to Struct?
	// Yes. right.
	// Please read the suggested file K1-1read.cpp



    for (int i = 0; i<NUM; i++) {
        if (rookies[i].sID == N) flag = i;
    }
    return flag;
}
