/////////////////////////////////////////////////////////
// polynomial.h
//
// provides struct for a polynomial
//
/////////////////////////////////////////////////////////

// always use include guards
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

//declare structs
typedef struct polynomial
{
    // array of coefficients
    // at coefficients[0] is the coefficient for x^0 etc.
    double* coefficients;
    //number of coefficients in the array.
    int length;
} polynomial;

// close include guard
#endif
 
