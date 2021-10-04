#include <iostream>
using namespace std;

int main() {
    int     *ptr;

    ptr = new int;
    *ptr = 20;
    cout << "Value: " << *ptr << endl; //20 - left as a "dangling pointer" &
    //cannot be accessed after reassigning it below

    //must use "delete" to release memory space
    delete ptr;

    ptr = new int;
    *ptr = 30;
    cout << "Value: " << *ptr << endl; //30
}