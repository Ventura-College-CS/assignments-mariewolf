#include "VectorQueue.h"
using namespace std;

template <class T, int size>
void VectorQueue<T, size>::enqueue(T el) {
    if (!isFull())
        queue.push_back(el);
    else cout << "Error: queue is full." << endl;
}

template <class T, int size>
T VectorQueue<T, size>::dequeue() {
    T el;
    if (!isEmpty()) {
        el = queue.front();
        queue.erase(queue.begin()); }
    else cout << "Error: queue is empty." << endl;
    return el;
}

template <class T, int size>
bool VectorQueue<T, size>::isFull() {
    return (queue.size() == 10);
}

template <class T, int size>
bool VectorQueue<T, size>::isEmpty() {
    return queue.empty();
}

template <class T, int size>
void VectorQueue<T, size>::printQueue() {
    if (!isEmpty()) {
        for (int i=0; i<queue.size(); i++)
            cout << queue.at(i) << " "; }
    if (isEmpty()) cout << "Error: nothing to print." << endl;
}

template <class T, int size>
void VectorQueue<T, size>::printStudents() {
    if (!isEmpty()) {
        for (int i=0; i<queue.size(); i++) {
            cout << (queue.at(i)).sid << " " << (queue.at(i)).sname << " ";
            cout << (queue.at(i)).scores[0] << " " << (queue.at(i)).scores[1] << endl; }
    }
    if (isEmpty()) cout << "Error: nothing to print." << endl;
}