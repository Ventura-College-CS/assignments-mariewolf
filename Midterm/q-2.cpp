#include <iostream>
#include <queue>
using namespace std;

class MyCompareFunction //copied from question 2
{
public:
	int operator()(const int &lhs, const int &rhs)
	{
		int l, r;
		l = lhs % 10;
		r = rhs % 10;
		return l < r;
	}
};

class Compare1 {
public:
	int operator()(const int &lhs, const int &rhs) {return lhs < rhs;}
};

class Compare2 {
public:
	int operator()(const int &lhs, const int &rhs)
	{
		int l, r;
		l = lhs % 10;
		r = rhs % 10;
		return l > r;
	}
};

int main() {
    priority_queue<int, vector<int>, MyCompareFunction> pq;
    priority_queue<int, vector<int>, Compare1> exq1;
    priority_queue<int, vector<int>, Compare2> exq2;

	pq.push(31); exq1.push(31); exq2.push(31);
	pq.push(45); exq1.push(45); exq2.push(45);
	pq.push(29); exq1.push(29); exq2.push(29);

	while (!pq.empty()) {
		cout << "Popped Value : " << pq.top() << endl;
		pq.pop();
	}

    cout << "\nFrom largest to smallest\n";
    while (!exq1.empty()) {
		cout << "Popped Value : " << exq1.top() << endl;
		exq1.pop();
	}

    cout << "\nReverse order of first function\n";
    while (!exq2.empty()) {
		cout << "Popped Value : " << exq2.top() << endl;
		exq2.pop();
	}
}