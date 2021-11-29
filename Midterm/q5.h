#ifndef Q5_H
#define Q5_H
#include <vector>
using namespace std;

const int N = 3;
class Student {
    private:
        int SID;
        string SName;
        double scores[N];
    public:
        Student() : SID(0), SName() {}
        Student(int i, string name, double *sc) : SID(i), SName(name) {
            for (int i=0; i<N; i++)
                scores[i] = sc[i];
        }
        int getID() {return SID;}
        string getName() {return SName;}
        double *getScores() {return scores;}
        void printScores() {
            cout << SID << "\t" << SName << "\t" << scores[0];
            cout << "  " << scores[1] << "  " << scores[2] << endl;
        }
};

template <class T>
class Stack {
    private:
        vector<T> pool;
    public:
        Stack() {pool.reserve(10);}
        void push(const T &el) {pool.push_back(el);}
        T pop() {
            T el = pool.back();
            pool.pop_back();
            return el; }
        T &topEl() {return pool.back();}
        bool isEmpty() {return pool.empty();}
        int size() {return pool.size();}
};

#endif