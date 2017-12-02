/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 2
 * fraction_15rws.h
 * Purpose: Create a Fraction class designed to hold fractions.
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 20/10/2017
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string FRACTION_EXCEPTION_ZERO_DENOMINATOR("Illegal Denominator! The denominator cannot be zero.");

/**
 * The fraction class declaration.
 * Class used to hold fractions.
 */
class Fraction {
    private:
        int numVal; // int to hold the numerator of the fraction
        int denVal; // int to hold the denominator of the fraction
    public:
        Fraction(); // empty class constructor, use as default constructor.
        Fraction(int numerator); // constructor that takes a numerator
        Fraction(int numerator, int denominator); // constructor that takes both a numerator and a denominator
        int numerator() const { return numVal; } // getter for the numerator, function
        int denominator() const { return denVal; } // getter for the denominator
        friend istream& operator >> (istream&, Fraction&); // overloaded input stream action
        friend ostream& operator << (ostream&, const Fraction&); // overloaded output stream action
        Fraction operator - () const; // overload methods
        friend Fraction operator + (const Fraction&, const Fraction&);
        friend Fraction operator - (const Fraction&, const Fraction&);
        friend Fraction operator * (const Fraction&, const Fraction&);
        friend Fraction operator / (const Fraction&, const Fraction&);
        friend bool operator > (const Fraction&, const Fraction&);
        friend bool operator < (const Fraction&, const Fraction&);
        Fraction operator += (const Fraction&);
        bool operator >= (const Fraction&);
        bool operator <= (const Fraction&);
        friend bool operator != (const Fraction&, const Fraction&);
        bool operator == (const Fraction&);
        Fraction operator ++ ();
        Fraction operator ++ (int);
        int greatestCommonFactor(int, int); // utility method/modifier to calculate the greatest common factor
};

/**
 * The FractionException class declaration.
 * Class used to validate user inputted fractions.
 */
class FractionException {
    public:
        explicit FractionException(const string& message); // constructor that takes reference to sting type, marked explicit to avoid possible implicit conversion
        string what() const; // method to return the exception message
    private:
        string exceptionMessage; // the exception message
};