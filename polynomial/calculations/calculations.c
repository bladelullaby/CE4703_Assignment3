#include "calculations.h"

int max(int a, int b);

polynomial* addPolynomials(polynomial* pol1, polynomial* pol2)
{
    int length = max(pol1->length, pol2->length);
    double* coefficients;
    coefficients = malloc(sizeof(double) * length);
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = 0.0;
        if(i < pol1->length)
            coefficients[i] += pol1->coefficients[i];
        if(i < pol2->length)
            coefficients[i] += pol2->coefficients[i];
    }
    
    return createPolynomial(coefficients, length);
}

polynomial* subtractPolynomials(polynomial* pol1, polynomial* pol2)
{
    int length = max(pol1->length, pol2->length);
    double* coefficients;
    coefficients = malloc(sizeof(double) * length);
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = 0.0;
        if(i < pol1->length)
            coefficients[i] += pol1->coefficients[i];
        if(i < pol2->length)
            coefficients[i] -= pol2->coefficients[i];
    }
    
    return createPolynomial(coefficients, length);
}

polynomial* multiplyPolynomial(polynomial* pol, double factor)
{
    int length = pol->length;
    double* coefficients;
    coefficients = malloc(sizeof(double) * length);
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = pol->coefficients[i] * factor;
    }
    
    return createPolynomial(coefficients, length);
}

polynomial* dividePolynomial(polynomial* pol, double factor)
{
    int length = pol->length;
    double* coefficients;
    coefficients = malloc(sizeof(double) * length);
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = pol->coefficients[i] / factor;
    }
    
    return createPolynomial(coefficients, length);
}

polynomial* normalizePolynomial(polynomial* pol)
{
    int order = getPolynomialOrder(pol);
    double highestOrderCoeff = pol->coefficients[order];
    double factor = 1.0 / highestOrderCoeff;
    
    return multiplyPolynomial(pol,factor);
    
}

int getPolynomialOrder(polynomial* pol)
{
    for(int i = pol->length - 1; i >= 0; i--)
    {
        if(pol->coefficients[i] != 0)
            return i;
    }
    return 0;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}
