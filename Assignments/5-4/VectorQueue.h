#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H
#include <vector>

template<class T, int size = 100>
class VectorQueue {
    private:
        vector<T> queue;
    public:
        VectorQueue() {};
        void enqueue(T el);
        T dequeue();
        bool isFull();
        bool isEmpty();
        void printQueue();
        void printStudents();
} ;

#endif