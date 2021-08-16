#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num, i, range1, range2;
    
    cout <<"Beginning of range: ";
    cin >> range1;
    cout <<"End of range: ";
    cin >> range2;
    
    for(num=range1; num<=range2; num++) {
        for(i=2; i<(num/2); i++) {
            if (num % i == 0)
                break;
        }
        
        if(i == num/2)
            cout << num << " - This number is prime.\n";
        else
            cout << num << " - Not prime.\n";
    }

    return 0;
}