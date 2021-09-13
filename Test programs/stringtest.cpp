#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//mostly copied from CS01/ch07/cooplab7-7prob.cpp

int finduserstring(char[], int, char[], int);
int main() {
        int cstrlen, userlen, position;
        char cstr[] = "Chocolate";
        char userstr[100];

        cstrlen = strlen(cstr);
        cout << "Input your string: " << endl;
        cin >> userstr;
        userlen = strlen(userstr);

        position = finduserstring(cstr, cstrlen, userstr, userlen);
        if (position != -1)
                cout << "Found your string at: " << position << endl;
        else
                cout << "Not found.\n";
        return 0;
}

int finduserstring(char cstr[], int cstrlen, char userstr[], int userlen) {
    int flag = -1;
    int counter = 0;
    for (int i=0; i<=(strlen(cstr)-strlen(userstr)); i++) {
        for (int j=0; j<=strlen(userstr); j++) {
            if (userstr[j] == cstr[i+j]) counter += 1;
            if (counter == userlen) flag = i;
        }
    }
    return flag;
}
