#include<iostream>
using namespace std;
int main() {
    int num1, num2;
    char op;
    cout << "Enter Two Numbers ";
    cin >> num1 >> num2;
    cout << "Enter Operation Which You Want To Do ";
    cin >> op ;
    if (op == '+')
        cout << num1 + num2 << endl;
    else if (op == '-')
        cout << num1 - num2 << endl;
    else if (op == '*')
        cout << num1 * num2 << endl;
    else if (op == '/')
        cout << (num2 != 0 ? num1 / num2 : 0) << endl;
    else
        cout << "Invalid operation!" << endl;
return 0;
}
