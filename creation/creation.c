#include "creation.h"

polynomial* createPolynomial()
{
    printf("enter length of polynomial: ");
    int length;
    scanf("%d", &length);

    double* coefficients;
    coefficients = malloc(sizeof(double) * length);

    for (int i = 0; i < length; i++)
    {
        double userCoEff;//co-eff
        printf("Please insert a co-efficent at power %d: ", i);
        scanf("%lf", &userCoEff);
        coefficients[i] = userCoEff;
    }

    polynomial* pol;
    pol = malloc(sizeof(polynomial));

    pol->length = length;
    pol->coefficients = coefficients;

    return pol;
}

void deletePolynomial(polynomial* pol)
{
    free(pol->coefficients);
    free(pol);
}
