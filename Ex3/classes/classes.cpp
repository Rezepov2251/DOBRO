
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex c;
    cout << c << endl; 

    Complex first(4, 3), b = 5;
    cout << first << ", " << b << endl; 

    Complex plus = b + 2;
    Complex minus = b - 2;
    Complex multiply = b * 5;
    Complex divide = b / 3;

    cout << plus << " " << minus << " " << multiply << " " << divide << endl;

    cout << first.Conjugate() << endl; 
    cout << first.Mod() << endl; 
    cout << first.Arg() << endl; 

    Complex v[4] = { 1, 2, Complex(2, 3) };
    for (int i = 0; i < 4; i++)
        cout << v[i] << " "; 
    cout << endl;

    Complex* pc = new Complex(1, 2);
    cout << *pc << endl; 
    double x = pc->Re;
    double y = pc->Im;
    delete pc;
    cout << x << " " << y << endl; 

    Complex* pk = new Complex[3]{ 1, Complex(4, 8) };
    cout << pk[1].Re << endl; 
    delete[] pk;

    return 0;
}
