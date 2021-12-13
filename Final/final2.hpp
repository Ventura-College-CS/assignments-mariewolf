#ifndef FINAL2_HPP
#define FINAL2_HPP
#include <iostream>
using namespace std;


class Course { //copied from question 1
    private:
        int courseID;
        string name;
        int credit;
    public:
        Course() : courseID(0), name(" "), credit(0) {}
        Course(int id, string nm, int cr) : courseID(id), name(nm), credit(cr) {}
        int getID() {return courseID;}
        string getName() {return name;}
        int getCredit() {return credit;}
};

#endif