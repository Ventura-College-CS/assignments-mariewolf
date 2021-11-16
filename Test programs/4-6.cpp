#include <iostream>
#include <fstream>
using namespace std;

struct Students {
    int ID;
    string name;
    int score[3];
} ;

void makeStudents(Students[], int); //fill struct arr by reading students.txt
void bubble(Students[], int); //sort all struct arrays by the ID
void binarySearch(Students[], int, int); //binary search function by finding the ID
void printStruct(Students[], int);

int main() {
    const int N = 10;
    Students arr[N];
    makeStudents(arr, N);
    printStruct(arr, N);
    bubble(arr, N);
    printStruct(arr, N);
    int target = 10007766;
    binarySearch(arr, N, target);

    return 0;
}

void bubble(Students arr[], int N) {
    cout << "\n\nBubble sort\n";
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<N-i-1; j++) {
            if (arr[j].ID > arr[j+1].ID) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void binarySearch(Students arr[], int N, int target) {
    cout << "\n\nBinary search\n";
    int first = 0;
    int foundIndex = -1;
    int last = N-1;
    while (first<last) {
        int mid = (first+last)/2;
        if (arr[mid].ID == target) {
            foundIndex = mid;
            cout << "Found student!\n" << arr[mid].ID << "\t" << arr[mid].name << "\t";
            cout << arr[mid].score[0] << "\t" <<arr[mid].score[1]  << "\t" << arr[mid].score[2];
            break;
        }
        if (arr[mid].ID < target) {
            first = mid + 1;
        }
        if (arr[mid].ID > target) {
            last = mid - 1;
        }
    }
    if (foundIndex == -1) cout << "Student not found." << endl;
}

void makeStudents(Students arr[], int N) {
    ifstream sBin("students.txt");
    if (!sBin) {printf("File open error!"); exit(0);} //check 1
    for (int i=0; i<N; i++)
        sBin >> arr[i].ID >> arr[i].name >> arr[i].score[0] >> arr[i].score[1] >> arr[i].score[2];
    sBin.close();
}

void printStruct(Students arr[], int N) {
    cout << "ID\t\tName\tScore1\tScore2\tScore3";
    for (int i=0; i<N; i++) {
        cout << "\n" << arr[i].ID << "\t" << arr[i].name << "\t" << arr[i].score[0] << "\t" <<arr[i].score[1]  << "\t" << arr[i].score[2];
    }
}