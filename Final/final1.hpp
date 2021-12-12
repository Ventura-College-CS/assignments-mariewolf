#ifndef FINAL1_HPP
#define FINAL1_HPP
#include <iostream>
using namespace std;


class Course {
    private:
        int courseID;
        string name;
        int credit;
    public:
        Course() {}
        int getID() {return courseID;}
        string getName() {return name;}
        int getCredit() {return credit;}
};

#endif