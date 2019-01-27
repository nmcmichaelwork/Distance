//
// edits by Noah McMichael
//

#ifndef DISTANCE_H

#define DISTANCE_H
#include <iostream>
using namespace std;

typedef int Feet;
typedef int Inches;

class Distance {  // Overloaded <<: prints x ft y inchs, 1 foot 1 inch, x ft, y inchs, or 0 inch
    friend ostream& operator<<( ostream&, const Distance& );
//  // Overloaded >>: takes two integers as ft and inchs.
    friend istream& operator>>( istream&, Distance& );

public:
    // Constructor: the default is 0 foot 0 inch
    // assumed that this acts dually as the default definition
    // and normal constructor
    Distance( Feet x = 0, Inches y = 0 );

    // Get mothds
    Feet getFeet( );
    Inches getInches( );

    //Put mothds
    void putFeet( Feet ); // optional
    void putInches( Inches ); // optional

    // Arithmetic operators
    Distance operator+( const Distance& ) const;
    Distance operator-( const Distance& ) const;
    double operator*( const Distance& ) const;
    double operator/( const Distance& ) const;
    Distance operator-( ) const;

//   Boolean comparison operators
    bool operator==( const Distance& ) const;
    bool operator!=( const Distance& ) const;
    bool operator>( const Distance& ) const;
    bool operator<( const Distance& ) const;
    bool operator>=( const Distance& ) const;
    bool operator<=( const Distance& ) const;

//   assumed that these operators would have the same definition as the +,-,/,* ops
    Distance& operator+=( const Distance& );
    Distance& operator-=( const Distance& );

private:
    Feet ft;
    Inches inchs;

    // Reduce Inches in up to 12 inchs
    void reduce( );
};
#endif

