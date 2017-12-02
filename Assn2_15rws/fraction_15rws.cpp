/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 2
 * fraction_15rws.cpp
 * Purpose: Create a Fraction class designed to hold fractions.
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 20/10/2017
 */

#include "fraction_15rws.h"

/* /////////////////////// */
/* Fraction Implementation */
/* /////////////////////// */

/* Constructors */

/**
 * Default constructor for the Fraction class, initializes numerator to 0 and denominator to 1.
 */
Fraction::Fraction() : numVal(0), denVal(1) {};

/**
 * Constructor for the fraction class that takes numerator and initializes denominator to 1.
 * @param numerator The numerator for the fraction.
 */
Fraction::Fraction(int numerator) : numVal(numerator), denVal(1) {}

/**
 * Constructor for the fraction class that takes numerator and denominator.
 * @param numerator The numerator for the fraction.
 * @param denominator The denominator for the fraction
 */
Fraction::Fraction(int numerator, int denominator) : numVal(numerator), denVal(denominator) {
    if (denominator == 0) { // first check if the denominator is valid, otherwise throw exception
        throw FractionException(FRACTION_EXCEPTION_ZERO_DENOMINATOR);
    } else {
        int gcf = greatestCommonFactor(abs(denominator), abs(numerator)); // get the greatest common factor
        numVal = numerator/gcf;
        denVal = denominator /gcf;
        if (denominator < 0) {
            denVal = abs(denominator/gcf);
            numVal = -numerator/gcf;
        }
    }
}

/* Overloads */

/**
 * Overloaded output stream handler.
 * @param os Reference to output stream.
 * @param fraction The fraction object reference to output.
 * @return The output stream.
 */
ostream& operator << (ostream& os, const Fraction& fraction) {
    os << fraction.numerator() << "/" << fraction.denominator(); // output the fraction in the nice format
    return os; // return the output stream
}

/**
 * Overloaded input stream handler.
 * @param is The input stream.
 * @param fraction The object fraction reference.
 * @return The input stream.
 */
istream& operator >> (istream& is, Fraction& fraction) {
    string input; // input string
    getline(is, input); // gets the line from i/o, i.e. from user
    string numeratorString;
    string denominatorString;
    bool inputFlag(false); // flag to check input, used to check if fraction with slash entered

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '/')
            inputFlag = true;
    }

    if (inputFlag) { // handle if fraction with slash entered
        for(int i = 0; i < input.length(); i++) {
            if(input[i] == '/'){
                numeratorString.append(input.substr(0,i)); // pick off the numerator
                denominatorString.append(input.substr(i+1,input.length() - 1)); // pick off the denominator
                fraction.numVal = atoi(numeratorString.c_str());
                fraction.denVal = atoi(numeratorString.c_str());
            }
        }
    } else { // handle case where number is entered.
        fraction.numVal = atoi(input.c_str());
        fraction.denVal = 1;
    }
    return is;
}

/**
 * Overloaded negation operator.
 * @return The result after operation, as a fraction.
 */
Fraction Fraction::operator - () const {
    return Fraction(-numVal, denVal);
}

/**
 * Overloaded addition operator.
 * @param add1 One fraction to add.
 * @param add2 Another fraction to add.
 * @return The resultant fraction after operation (addition).
 */
Fraction operator + (const Fraction& add1, const Fraction& add2) {
    if (add2.denVal == add1.denVal) { // if the denominators are the same, no need to modify result denominator
        return Fraction(add2.numVal + add1.numVal, add1.denVal);
    } else {
        return Fraction(add2.numVal * add1.denVal + add2.denVal * add1.numVal, add2.denVal * add1.denVal);
    }
}

/**
 * Overloaded sutraction operator.
 * @param sub1 One fraction to subtract.
 * @param sub2 One fraction to subract.
 * @return The resultant fraction after operation (subtraction).
 */
Fraction operator - (const Fraction& sub1, const Fraction& sub2) {
    if (sub2.denVal == sub1.denVal) { // if the denominators are the same, no need to modify result denominator
        return Fraction(sub1.numVal - sub2.numVal, sub2.denVal);
    } else {
        return Fraction(sub1.numVal * sub2.denVal - sub2.numVal * sub1.denVal, sub2.denVal * sub1.denVal);
    }
}

/**
 * Overloaded multiplication operator.
 * @param mul1 One fraction to multiply.
 * @param mul2 Another fraction to multiply.
 * @return The resultant fraction after operation (multiplication).
 */
Fraction operator * (const Fraction& mul1, const Fraction& mul2) {
    return Fraction(mul1.numVal * mul2.numVal, mul1.denVal * mul2.denVal);
}

/**
 * Overloaded division operator.
 * @param div1 One fraction to divide.
 * @param div2 Another fraction to divide.
 * @return The resultant fraction after operation (division).
 */
Fraction operator / (const Fraction& div1, const Fraction& div2) {
    return Fraction(div1.numVal * div2.denVal, div1.denVal * div2.numVal);
}

/**
 * Overloaded less than operator.
 * @param lesser One fraction to use to compare.
 * @param greater One fraction to use to compare.
 * @return The result after operation.
 */
bool operator < (const Fraction& lesser, const Fraction& greater) {
    if (lesser.denVal == greater.denVal) {
        if (lesser.numVal < greater.numVal) {
            return false;
        }
        return true;
    } else {
        if (lesser.numVal * greater.denVal < greater.numVal * lesser.denVal) {
            return true;
        }
        return false;
    }
}

/**
 * Overloaded greater than operator.
 * @param lesser One fraction to use to compare.
 * @param greater One fraction to use to compare.
 * @return The result after operation.
 */
bool operator > (const Fraction& greater, const Fraction& lesser) {
    if (greater.denVal == lesser.denVal) {
        if (greater.numVal > lesser.numVal) {
            return false;
        }
        return true;
    } else {
        if (greater.numVal * lesser.denVal > lesser.numVal * greater.denVal) {
            return true;
        }
        return false;
    }
}

/**
 * Overloaded greater than or equal to operator.
 * @param greaterOrEqual The fraction to operate with.
 * @return The result after operation.
 */
bool Fraction::operator <= (const Fraction& greaterOrEqual) {
    if (denVal == greaterOrEqual.denVal) {
        if (numVal <= greaterOrEqual.numVal) {
            return false;
        }
        return true;
    } else {
        numVal = numVal * greaterOrEqual.denVal;
        if (numVal <= greaterOrEqual.numVal * denVal) {
            return true;
        }
        return false;
    }
}


/**
 * Overloaded less than or equal to operator.
 * @param greaterOrEqual The fraction to operate with.
 * @return The result after operation.
 */
bool Fraction::operator >= (const Fraction& lessOrEqual) {
    if (denVal == lessOrEqual.denVal) {
        if (numVal >= lessOrEqual.numVal) {
            return false;
        }
        return true;
    } else {
        numVal = numVal*lessOrEqual.denVal;
        if (numVal >= lessOrEqual.numVal*denVal) {
            return true;
        }
        return false;
    }
}

/**
 * Overloaded addition and assignment operator.
 * @param addAssign Fraction to use operator on.
 * @return The result after operation.
 */
Fraction Fraction::operator += (const Fraction& addAssign) {
    if (denVal == addAssign.denVal)
        numVal += addAssign.numVal;
    else {
        numVal = numVal*addAssign.denVal + addAssign.numVal*denVal;
        denVal = denVal*addAssign.denVal;
    }

    return *this;
}

/**
 * Overloaded negation comparison operator.
 * @param equal One fraction to compare.
 * @param negate One fraction to compare.
 * @return The result after operation.
 */
bool operator != (const Fraction& equal, const Fraction& negate) {
    if (equal.numVal != negate.numVal || equal.denVal != negate.denVal)
        return true;
    return false;
}

/**
 * Overloaded equality operator.
 * @param equal Fraction to perform operation on.
 * @return True if the numerator and denominator are equal.
 */
bool Fraction::operator == (const Fraction& equal) {
    if (numVal == equal.numVal && denVal == equal.denVal) {
        return true;
    }
    return false;
}

/**
 * Overloaded post increment.
 * @param diff Differentiator param to pre increment declaration.
 * NOTE: Is this the only way? Potentially revisit.
 * @return The new fraction after operation.
 */
Fraction Fraction::operator ++ (int diff) {
    Fraction inr(numVal, denVal);
    numVal += denVal;
    return inr;
}

/**
 * Overloaded pre increment.
 * @return The new fraction after operation.
 */
Fraction Fraction::operator ++ () {
    numVal += denVal;
    return *this;
}

/* Utilities */

/**
 * Method that calculates the greatest common factor of two numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The greatest common factor.
 */
int Fraction::greatestCommonFactor(int a, int b) {
    if (a <= b && (b % a == 0)) {
        return a;
    } else if (b < a) {
        return greatestCommonFactor(b, a);
    } else {
        return greatestCommonFactor(a, b % a);
    }
}

/* ////////////////////////////////// */
/* Fraction Exception Implementation */
/* //////////////////////////////// */

/**
 * Fraction exception constructor.
 * Utilizes initialisation list to intialize message member.
 * @param m The error message, or description of the exception.
 */
FractionException::FractionException(const string& message) : exceptionMessage(message) {}

/**
 * Fraction exception error message method definition.
 * @return The error message that was passed when exception created.
 */
string FractionException::what() const {
    return exceptionMessage; // output error message, initialized in constructor.
}