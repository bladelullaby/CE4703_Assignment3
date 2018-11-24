#include "testMain.h"

int main(int argc, char** argv)
{
    if(testCreation() == 1)
        printf("createPolynomial tested: OK\n");
    else
        printf("createPolynomial tested: ERROR\n");
}

int testCreation()
{
    double* coefficients;
    double* expected_coefficients;
    polynomial* pol1;
    int ret = 1;
    
    
    printf("\ncreatePolynomial: test 1\n");
    coefficients = malloc(sizeof(double) * 5);
    coefficients[0] = 1;
    coefficients[1] = 1;
    coefficients[2] = 1;
    coefficients[3] = 2;
    coefficients[4] = 0;
    pol1 = createPolynomial(coefficients, 5);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 1;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 1;
    expected_coefficients[3] = 2;
    expected_coefficients[4] = 0;
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d : %lf  -  %lf\n", i, pol1->coefficients[i], expected_coefficients[i]);
        if(pol1->coefficients[i] != expected_coefficients[i])
            ret = 0;
    }
    
    free(expected_coefficients);
    free(coefficients);
    free(pol1);
    
    printf("\ncreatePolynomial: test 2\n");
    coefficients = malloc(sizeof(double) * 5);
    coefficients[0] = 7.1234;
    coefficients[1] = 0;
    coefficients[2] = 25;
    coefficients[3] = 2;
    coefficients[4] = 33.999;
    pol1 = createPolynomial(coefficients, 5);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 7.1234;
    expected_coefficients[1] = 0;
    expected_coefficients[2] = 25;
    expected_coefficients[3] = 2;
    expected_coefficients[4] = 33.999;
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d : %lf  -  %lf\n", i, pol1->coefficients[i], expected_coefficients[i]);
        if(pol1->coefficients[i] != expected_coefficients[i])
            ret = 0;
    }
    
    return ret;
}
