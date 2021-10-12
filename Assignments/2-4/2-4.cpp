#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
};

Students *makeStudents(int);
void printStudents(Students * const, int);
void sortStudents(Students * const, int);


int main() {
	const int N = 10;
	Students *ptr;

	ptr = makeStudents(N);
	cout << "Unsorted students: \n";
	printStudents(ptr, N);
	sortStudents(ptr, N);
	cout << "\nSorted students: \n";
	printStudents(ptr, N);

}

Students *makeStudents(int N) {
	ifstream 	ifs;
    Students    *ptr= new Students [N];

    ifs.open("students.txt");
    if ( ifs.fail()) {
        cerr << "File open error\n";
        exit(0);
    }

	for(int i=0;i<N; i++) {
        ifs >> (ptr+i)->sid >> (ptr+i)->sname;
        for(int j=0; j<NUM_SCORES; j++)
			ifs >> (ptr+i)->scores[j] ;
		if ( ifs.fail() ) {
			cerr << "File read error\n";
			exit(0);
		}
    }
	return ptr;
}

void printStudents(Students *x, int N) {
	cout <<"Student ID\tName\tScore1\tScore2\tScore3\tSum\n";
	for (int i=0; i<N; i++) {
		int sum = 0;
		cout << x[i].sid << "\t" << x[i].sname << "\t";
		for (int j=0; j<NUM_SCORES; j++) {
        	cout << x[i].scores[j] << "\t";
			sum += x[i].scores[j];
		}
		cout << sum << "\n";
	}
}

void sortStudents(Students *x, int N) {
    int sum1=0, sum2=0;
    for( int i=0; i< N-1; i++ ) {
	    for( int j=0; j<N-1; j++) {
		    for(int k=0; k<3; k++) {
                sum1 += x[j].scores[k];
                sum2 += x[j+1].scores[k]; }    
		    if ( sum1 > sum2)
                swap(x[j], x[j+1]);
			sum1 = 0;
	        sum2 = 0;
	    }
    }
}
