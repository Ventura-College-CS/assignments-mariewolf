#include <iostream>
#include <cstring>
using namespace std;

struct Students{
    int id;
    char *name; //when using array [char name[10]], then we can use "strcpy(s1.name, "John");"
    //without allocating space
};

int main() {
    Students s1;
    s1.id = 10;
    s1.name = new char [20]; //because of the pointer, we need to allocate space
    strcpy(s1.name, "John"); //s1: id=10, name=john

    Students s2;
    s2 = s1; //s1 & s2 will "share" the memory space for name. Changing one will change the other

    cout << "S2 id:" << s2.id << endl;
    cout << "S2 name: " << s2.name << endl;

    delete s2.name; 
}