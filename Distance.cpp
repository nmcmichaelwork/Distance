//
// // edits by Noah McMichael
//

#include "Distance.h"

//Constructor: the default is 0 foot 0 inch
Distance::Distance( Feet x, Inches y ) : ft(x), inchs(y)
{
    reduce();
}
// getter methods return feet or inches of this obejct
Feet Distance::getFeet( )
{
    return ft;
}
Inches Distance::getInches( )
{
    return inchs;
}

//// Put mothds
void Distance::putFeet( Feet x)
{
    ft = x;
}
void Distance::putInches( Inches y)
{
    inchs = y;
}// optional
// add and subtract work by creating a new Distance object
// and setting it's feet/inchs to the addition of the current
// Distance object that the reference being passed in
Distance Distance::operator+( const Distance& rhs) const
{
    Distance W;
//    W.feet = feet;
//    W.inchs = inchs;
    W.ft = ft + rhs.ft;
    W.inchs = inchs + rhs.inchs;
    W.reduce();
    return(W);
}
Distance Distance::operator-( const Distance& rhs) const
{
    Distance W;
    W.ft = ft - rhs.ft;
    W.inchs = inchs - rhs.inchs;
    W.reduce();
    return W;
}
// Returns the area of the two distances multiplied together. This is done by
// converting everything to inches, multiplying each side length, and dividing by 144. This value is
// called asDoub, as this operation converts standard integer feet and inches to
// values containing doubles.

//Update: the logic is still the same but additional variables are un
double Distance::operator*( const Distance& rhs) const
{
    Distance result;
    //int truncDec;
    //double rmndrDec;
    double asDoub;
    asDoub = ((double(12 * ft)  + double(inchs)) *
            (double(12 * rhs.ft) + double(rhs.inchs))) / 144;
    return asDoub;

    // code if a distance obejct is to be returned.
//    truncDec = int (asDoub);
//    rmndrDec = asDoub - double (truncDec);
//    result.ft = truncDec;
//    result.inchs = rmndrDec * 12;
//    result.reduce();
    //return result;

// The decimal is then truncated (called truncDec) and this value
// is subtracted from asDoub to leave the remaining decimal (rmndrDec). Since this decimal is
// a ratio, it needs to be multiplied by 12 to convert back to a value in inches. The final values of truncDec
// and rmndrDec are reduced and returned as a Distance object called result.


}
// returns a ratio of the lhs and rhs distance objects, by converting all values
// to inches, and performing simple division. If a distance on the denominator (rhs) is
// equal to zero, an error is thrown.
double Distance::operator/( const Distance& rhs) const
{
    double rhsInchs = ((rhs.ft * 12) + rhs.inchs);
    double ratio = ((ft * 12) + inchs) / rhsInchs;
    if(rhsInchs == 0)
    {
        cerr << "zero division!!" << endl;
    }
    return ratio;
}
//Distance Distance::operator/( const double rhs) const
//{
//    Distance W;
//    W.inchs = ((ft * 16)+ inchs) / rhs;
//    W.ft = 0;
//    W.reduce();
//    return W;
//

//}
//converts positive variables to negative ones. example: T = 5, -T == -5. The value
// is returned.
Distance Distance::operator-( ) const
{
    Distance W;
    W.ft = -ft;
    W.inchs = -inchs;
    return W;
}

// the following 6 functions test equality of the feet and inches passed through the rhs Distance obj
// using traditional for loop methods, cycling through each possible outcome of the input, and determining
// if the operation at hand is true or false, a boolean value is returned.
bool Distance::operator==( const Distance& rhs) const
{

    if (ft == rhs.ft && inchs == rhs.inchs) {
        return true;
    }
    return false;
}
bool Distance::operator!=( const Distance& rhs) const
{
    if(ft == rhs.ft && inchs == rhs.inchs)
    {
        return false;
    }
    return true;
}
bool Distance::operator>( const Distance& rhs) const
{
    if(ft > rhs.ft)
    {
        return true;
    }
    else if(ft < rhs.ft)
    {
        return false;
    }
    else if(inchs > rhs.inchs)
    {
        return true;
    }
    else return false;
}
bool Distance::operator<( const Distance& rhs) const
{
    if(ft < rhs.ft)
    {
        return true;
    }
    else if(ft > rhs.ft)
    {
        return false;
    }
    else if(inchs < rhs.inchs)
    {
        return true;
    }
    else return false;
}
bool Distance::operator>=( const Distance& rhs) const
{
    if(ft > rhs.ft)
    {
        return true;
    }
    else if(ft < rhs.ft)
    {
        return false;
    }
    else if(inchs >= rhs.inchs)
    {
        return true;
    }
    else return false;
}
bool Distance::operator<=( const Distance& rhs) const
{
    if(ft < rhs.ft)
    {
        return true;
    }
    else if(ft > rhs.ft)
    {
        return false;
    }
    else if(inchs <= rhs.inchs)
    {
        return true;
    }
    else return false;
}
// implements the += and -= operations. Done by adding or subtracting the rhs object
// (lhs) and returning it.
Distance& Distance::operator+=( const Distance& rhs)
{
    ft += rhs.ft;
    inchs += rhs.inchs;
    reduce();

    return *this;
}
Distance& Distance::operator-=( const Distance& rhs)
{
    ft -= rhs.ft;
    inchs -= rhs.inchs;
    reduce();

    return *this;
}

// formats and prints out distance arg specified. An outstream object arg is
// created to be returned. Formatting includes proper singular/plural verbs. If
// there are zero feet, or zero inches, they are not printed out, respectively.
ostream& operator<<( ostream& os, const Distance& D )
{
    if((D.ft == 1) || (D.ft == -1))
    {
        os << D.ft << " foot ";
    }
    else if(D.ft == 0)
    {
    }
    else
    {
        os << D.ft << " feet ";
    }

    if((D.inchs == 1) || (D.inchs == -1))
    {
        os << D.inchs << " inch ";
    }
    else if(D.inchs == 0)
    {
    }
    else
    {
        os << D.inchs << " inches ";
    }

    if((D.ft == 0) && (D.inchs == 0))
    {
        os << D.ft << " feet ";
        os << D.inchs << " inches ";
    }
    return os;
}
// Takes in the next two numbers from the console as doubles,
// converts them to ints, first one being feet and second inches.
// then reduced before being returned.
istream& operator>>( istream& is, Distance& D)
{
    double feetIn, inchsIn;
    is >> feetIn >> inchsIn;
    D.ft = int(feetIn);
    D.inchs = int (inchsIn);
    D.reduce();
    return is;
}

// checks if inchs equal 16, if they do, 1 foot is added and inchs are reset
// if inchs are greater than 16, then the mod is taken to check if the current inchs
// are divisible by 16, if so, the current inch / 16 are added to feet
// otherwise, a leftover inch count is increased and the number of inchs is decreased.

//Reduce function courtesy of Professor Fukuda
void Distance::reduce()
{
    ft += inchs / 12;
    inchs %= 12;
    if (ft > 0 && inchs < 0)
    {
        --ft;
        inchs = 12 + inchs;
    } else if ( ft < 0 && inchs > 0 )
    {
        ++ft;
        inchs = -12 + inchs;
    }
}
