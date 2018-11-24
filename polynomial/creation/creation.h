/////////////////////////////////////////////////////////
// creation.h
//
// provides functions to control the creation and deletion of polynomials
//
/////////////////////////////////////////////////////////


// always use include guards
#ifndef CREATION_H
#define CREATION_H

//include headers
#include <stdlib.h>
#include "../polynomial.h"

//declare structs


// declare "public" function interfaces
polynomial* createPolynomial(double* coefficients, int length);
void deletePolynomial(polynomial* polynomial);

// close include guard
#endif
 
