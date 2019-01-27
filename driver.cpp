#include "Distance.h"
#include <iostream>
using namespace std;

int main( )
{
    // creates several distance objects
    Distance d1( -5, 30 ), d2(5, -31 ), d3( 2, 5 ), d4( 1 ), d5, d6;

    cout << "type two integers for d6: ";
    cin >> d6; // tests console input

    //prints distance objects simplified
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d3 = " << d3 << endl;
    cout << "d4 = " << d4 << endl;
    cout << "d5 = " << d5 << endl;
    cout << "d6 = " << d6 << endl;
    cout << "-d4 = " << -d4 << endl; // tests unary operator
    cout << "\n";


    // addition, subtraction, ratio, divide by zero tests
    cout << "d1 + d2 + d3 = " << d1 + d2 + d3 << endl;
    cout << "d1 - d2 - d3 = " << d1 - d2 - d3 << endl;
    cout << "d1 / d2 = " << d1 / d2 << endl;
    cout << "d1 / d5 = " << d1 / d5 << endl;
    cout << "\n";

    // multiplication (square feet) test
    cout << "Sqfeet( d2 * d3 ) = " << d2 * d3 <<endl;
    cout << "\n";

    //boolean operator tests
    cout << "d1 <= d2 is " << ( ( d1 <= d2 ) ? "true" : "false" ) << endl;
    cout << "d2 >= d3 is " << ( ( d2 >= d3 ) ? "true" : "false" ) << endl;
    cout << "d3 > d4 is " << ( ( d3 > d4 ) ? "true" : "false" ) << endl;
    cout << "d4 < d5 is " << ( ( d4 < d5 ) ? "true" : "false" ) << endl;
    cout << "d1 == d1 is " << ( ( d1 == d1 ) ? "true" : "false" ) << endl;
    cout << "d1 != d1 is " << ( ( d1 != d1 ) ? "true" : "false" ) << endl;
    cout << "\n";

    // tests of assignment operators += and -=
    cout << "( d1 += d2 ) = " << ( d1 += d2 ) << endl;
    cout << "(d5 += d1) += d2 is " << ( (d5 += d1) += d2 ) << endl;
    cout << "(d6 -= d4) -= d3 is " << ( (d6 -= d4) -= d3 ) << endl;
}