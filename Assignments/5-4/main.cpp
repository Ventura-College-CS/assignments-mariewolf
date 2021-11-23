#include <iostream>
#include <time.h>
using namespace std;
#include "VectorQueue.hpp"

const int 	NUM_SCORES = 2;
struct Students {
	int 	sid;
	string 	sname;
	double 	scores[NUM_SCORES];
};

int main() {
    VectorQueue<int, 5> q;
    q.dequeue(); //calling dequeue when queue is empty
    srand(time(NULL));

    for (int i=0; i<10; i++) {
        int N = rand() % 20 + 1;
        q.enqueue(N); //enqueue 10 random integers
    }
    q.printQueue(); cout << endl;
    q.enqueue(25); //calling enqueue when queue is full

    int t = 5;
    for (int i=0; i<t; i++)
        q.dequeue(); //dequeue t integers
    q.printQueue(); cout << endl << endl;

    VectorQueue<Students, 10> s;
    Students test1, test2, test3;
    test1.sid = 10001111; test1.sname = "James"; test1.scores[0] = 100; test1.scores[1] = 90;
    test2.sid = 10009999; test2.sname = "Brick"; test2.scores[0] = 80; test2.scores[1] = 90;
    test3.sid = 10009999; test3.sname = "Amy"; test3.scores[0] = 90; test3.scores[1] = 90;
    s.enqueue(test1); //enqueue 3 test students
    s.enqueue(test2);
    s.enqueue(test3);
    s.printStudents(); cout << endl;

    s.dequeue(); //dequeue 2 students
    s.dequeue();
    s.printStudents();

    return 0;
}