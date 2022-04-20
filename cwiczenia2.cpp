#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    //testowanie
    Rational u1(2,6);
    Rational u2(2,5);
    Rational u3;
    cout << "Set u3: n[ENTER]d\n\n";
    cin >> u3;
    cout <<"Konstruktor domniemany: "<< u3 << endl;
    Rational u4(u1);
    cout << "Rationals are set to: \n" << u1 << endl << u2 << endl << u3 << endl << u4 << endl;
    cout << "u1 + u2 = " << u1+u2 << endl;
    cout << "u1 - u2 = " << u1-u2 << endl;
    cout << "u1 * u2 = " << u1*u2 << endl;
    cout << "u1 / u2 = " << u1/u2 << endl;
    Rational r;
    Rational r1(1, 4);
    Rational r2(3, 5);
    r = Rational(2) + r1 + r2 + 1;
    return 0;
}