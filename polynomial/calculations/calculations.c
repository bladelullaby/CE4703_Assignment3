#include "calculations.h" // inclusion of header files

int max(int a, int b); // declaration of function

polynomial* addPolynomials(polynomial* pol1, polynomial* pol2) // requires two polynomials
{
    int length = max(pol1->length, pol2->length); // creates int length, which is the length of the longest polynomial
    double* coefficients;
    coefficients = malloc(sizeof(double) * length); // allocates memory according to the length of the longest polynomial
    
    for(int i = 0; i < length; i++) // adds coefficients together
    {
        coefficients[i] = 0.0;
        if(i < pol1->length)
            coefficients[i] += pol1->coefficients[i]; // adds polynomial 1 coefficients to empty coefficient array
        if(i < pol2->length)
            coefficients[i] += pol2->coefficients[i]; // adds polynomial 2 coefficients to coefficient array
    }
    
    return createPolynomial(coefficients, length); // creates new added polynomial
}

polynomial* subtractPolynomials(polynomial* pol1, polynomial* pol2) // requires two polynomials
{
    int length = max(pol1->length, pol2->length); // creates int length, the length of the longest polynomial
    double* coefficients;
    coefficients = malloc(sizeof(double) * length); // allocates memory according to the length of the longest polynomial
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = 0.0;
        if(i < pol1->length)
            coefficients[i] += pol1->coefficients[i]; // adds polynomial 1 coefficients to empty coefficient array
        if(i < pol2->length)
            coefficients[i] -= pol2->coefficients[i]; // subtracts polynomial 2 coefficients from coefficient array
    }
    
    return createPolynomial(coefficients, length); // creates one newly subtracted polynomial
}

polynomial* multiplyPolynomial(polynomial* pol, double factor) // requires one polynomial, and a factor to multiply by
{
    int length = pol->length; // length of polynomial
    double* coefficients;
    coefficients = malloc(sizeof(double) * length); // allocates memory according to the length of the polynomial
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = pol->coefficients[i] * factor; // multiplies each coefficient by the factor
    }
    
    return createPolynomial(coefficients, length); // creates new multiplied polynomial
}

polynomial* dividePolynomial(polynomial* pol, double factor) // requires one polynomial and a factor to divide by
{
    int length = pol->length; // length of polynomial
    double* coefficients;
    coefficients = malloc(sizeof(double) * length); // allocates memory according to the length of the polynomial
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = pol->coefficients[i] / factor; // divides each coefficient by the factor 
    }
    
    return createPolynomial(coefficients, length); // creates new divided polynomial
}

polynomial* normalizePolynomial(polynomial* pol) // requires one polynomial
{
    int order = getPolynomialOrder(pol); // gets the highest order of the polynomial
    double highestOrderCoeff = pol->coefficients[order]; // gains the coefficient of the highest order in the polynomial
    double factor = 1.0 / highestOrderCoeff; // puts the coefficient over 1 to gain the factor
    
    return multiplyPolynomial(pol,factor); // multipies the factor by the polynomial in question
    
}

int getPolynomialOrder(polynomial* pol) // used in normalizePolynomial
{
    for(int i = pol->length - 1; i >= 0; i--) // starts at the length of the polynomial, and decreases until it finds the highest order
    {
        if(pol->coefficients[i] != 0)
            return i; 
    }
    return 0;
}

int max(int a, int b) // requires two integers, used to establish the largest of two polynomials above
{
    return (a > b ? a : b); // returns the largest of two values
}
