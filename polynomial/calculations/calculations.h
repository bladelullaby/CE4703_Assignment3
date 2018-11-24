/////////////////////////////////////////////////////////
// calculations.h
//
// provides functions for calculations on polynomials
//
/////////////////////////////////////////////////////////


// always use include guards
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

//include headers
#include <stdlib.h>
#include "../polynomial.h"

//declare structs


// declare "public" function interfaces
polynomial* addPolynomials(polynomial* pol1, polynomial* pol2);
polynomial* subtractPolynomials(polynomial* pol, polynomial* polSub);
polynomial* multiplyPolynomial(polynomial* pol, double factor);
polynomial* diviidePolynomial(polynomial* pol, double factor);
polynomial* normalizePolynomial(polynomial* pol);
int getPolynomialOrder(polynomial* pol);

// close include guard
#endif
 
