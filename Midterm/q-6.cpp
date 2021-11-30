#include "q6.h"
#include <queue>

int main() {
    //main function

    double sc1[N] = {75.8, 80.1, 85.2};
    double sc2[N] = {30.4, 20.5, 60.3};
    double sc3[N] = {99.9, 100, 98.5};
    double sc4[N] = {50.5, 65.3, 40.5};
    double sc5[N] = {90.5, 95.5, 91.2};

    Student Student1(100, "John", sc1);
    Student Student2(103, "James", sc2);
    Student Student3(102, "Brick", sc3);
    Student Student4(104, "Amy", sc4);
    Student Student5(101, "Bill", sc5);

    priority_queue<Student, vector<Student>, StudentCompare<Student>> pq;
    pq.push(Student1);
    pq.push(Student2);
    pq.push(Student3);
    pq.push(Student4);
    pq.push(Student5);
}