#ifndef Q5_H
#define Q5_H
#include <vector>
using namespace std;

class Student {
    private:
        int SID;
        string SName;
        double scores[3];
    public:
        Student() : SID(0), SName() {}
        Student(int i, string name, double *sc);
        int getID();
        string getName();
        double *getScores();
};

template <class T>
class Stack {
    private:
        vector<T> pool;
    public:
        Stack();
        void push(const T &el);
        T pop();
        T &topEl();
        bool isEmpty();
        int size();
};

#endif