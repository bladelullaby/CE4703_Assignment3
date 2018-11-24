#include "creation.h"

polynomial* createPolynomial(double* coefficients, int length)
{
    
    polynomial* pol;
    pol = malloc(sizeof(polynomial));
    double* coefficients2 = malloc(sizeof(double) * length);

    for(int i = 0; i < length; i++)
    {
        coefficients2[i] = coefficients[i];
    }
    
    pol->length = length;
    pol->coefficients = coefficients2;

    return pol;
}

void deletePolynomial(polynomial* pol)
{
    free(pol->coefficients);
    free(pol);
}
