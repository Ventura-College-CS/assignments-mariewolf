#include "genStack.h"
#include <ctime>
#include <iostream>
using namespace std;

class AddingNumbers {
    private:
        Stack<int> opr1, opr2, result;
        int len_opr1, len_opr2;
    public:
        AddingNumbers() {
            len_opr1 = 10;
            len_opr2 = 10;
            initOperands();
        }
        AddingNumbers(int len1, int len2) {
            len_opr1 = len1;
            len_opr2 = len2;
            initOperands();
        }
        void initOperands() {
            srand(time(0));
            for (int i=0; i<len_opr1; i++)
                opr1.push(rand()%10);
            for (int i=0; i<len_opr2; i++)
                opr2.push(rand()%10);
        }
        void printOperands() {
            /*
            cout << "\nOperand 1:\t";
            for (int i=0; i<len_opr1; i++) {
                int tmp = opr1.pop();
                cout << tmp;
                opr1.push(tmp);
            }
            cout << "\nOperand 2:\t";
            for (int i=0; i<len_opr2; i++) {
                int tmp = opr2.pop();
                cout << tmp;
                opr2.push(tmp);
            } */
            cout << "Operand 1: \t";
            opr1.print();
            cout << "Operand 2: \t";
            opr2.print();

        }
        void printResult() {
            cout << "Result: \t";
            while (!result.isEmpty())
                cout << result.pop();
        }
        void addOperands() {
            int left, right, tmpres;
            int carry = 0;

            while (!(opr1.isEmpty()) || !(opr2.isEmpty())) {
                left = opr1.isEmpty() ? 0:opr1.pop();
                right = opr2.isEmpty() ? 0:opr2.pop();
                tmpres = left+right+carry;
                carry = (tmpres >= 10) ? 1:0;
                if (tmpres >= 10) tmpres -= 10;
                result.push(tmpres);
            }
            if (carry) result.push(carry);
        }
        void subtractOperands() {
            int left, right, tmpres;
            int carry = 0;
            //need to add operand check
            while (!(opr1.isEmpty()) || !(opr2.isEmpty())) {
                left = opr1.isEmpty() ? 0:opr1.pop();
                left += carry;
                right = opr2.isEmpty() ? 0:opr2.pop();
                if (left > right || left == right) {
                    tmpres = left-right;
                    carry = 0;
                }
                else {
                    tmpres = 10 - right + left;
                    carry = -1;
                }
                result.push(tmpres);
            }
        }
} ;

int main() {
    AddingNumbers st(3,3);
    AddingNumbers sub(3,2);
    st.printOperands();
    st.addOperands();
    st.printResult();
    cout << endl << endl;
    sub.printOperands();
    sub.subtractOperands();
    sub.printResult();
    return 0;
}