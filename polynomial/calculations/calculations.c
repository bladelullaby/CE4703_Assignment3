#include "calculations.h"

int max(int a, int b);

/*polynomial* addPolynomials(polynomial* pol1, polynomial* pol2)
{
    int length = max(pol1->length, pol2->length);
    double* coefficients;
    coefficients = malloc(sizeof(double) * length);
    
    for(int i = 0; i < length; i++)
    {
        coefficients[i] = 0.0;
        if(i < pol1->length)
            coefficients[i] += pol1->coefficients[i]
        if(i < pol2->length)
            coefficients[i] += pol2->coefficients[i]
    }
    
    createPolynomial()
}*/


polynomial* subtractPolynomials(polynomial* pol, polynomial* polSub);
polynomial* multiplyPolynomial(polynomial* pol, double factor);
polynomial* diviidePolynomial(polynomial* pol, double factor);
polynomial* normalizePolynomial(polynomial* pol);
int getPolynomialOrder(polynomial* pol);

int max(int a, int b)
{
    return (a > b ? a : b);
}
