#include<iostream>
using namespace std;

int main() {
    int a = 10;
    int &b = a;

    int c = 40;
    b = c;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}