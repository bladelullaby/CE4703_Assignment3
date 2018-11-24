#include "testMain.h"

int equal(double a, double b, double threshhold);

int main(int argc, char** argv)
{
    if(testCreation() == 1)
        printf("createPolynomial tested: OK\n");
    else
        printf("createPolynomial tested: ERROR\n");
    
    if(testAddition() == 1)
        printf("addPolynomials tested: OK\n");
    else
        printf("addPolynomials tested: ERROR\n");
    
    if(testSubtraction() == 1)
        printf("subtractPolynomials tested: OK\n");
    else
        printf("subtractPolynomials tested: ERROR\n");
}

int equal(double a, double b, double threshhold)
{
    double c = a - b;
    if(c < threshhold && c > -1 * threshhold)
        return 1;
    else 
        return 0;
}

int testCreation()
{
    double threshhold = 0.001;
    double* coefficients;
    double* expected_coefficients;
    polynomial* pol1;
    // return 1 means all ok
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
        printf("%d : %lf  -  %lf\n", i, coefficients[i], expected_coefficients[i]);
        if(!equal(coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
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
        printf("%d : %lf  -  %lf\n", i, coefficients[i], expected_coefficients[i]);
        if(!equal(coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;
    }
    
    free(expected_coefficients);
    free(coefficients);
    free(pol1);
    
    return ret;
}

int testAddition()
{
    double threshhold = 0.001;
    double* coefficients1;
    double* coefficients2;
    double* expected_coefficients;
    polynomial* pol1;
    polynomial* pol2;
    polynomial* result;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\naddPolynomials: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = 5.44;
    coefficients2[1] = 123;
    coefficients2[2] = 5.5;
    coefficients2[3] = 0.22;
    coefficients2[4] = 0;
    pol2 = createPolynomial(coefficients2, 5);
    
    result = addPolynomials(pol1,pol2);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 8.04;
    expected_coefficients[1] = 124;
    expected_coefficients[2] = 11.27;
    expected_coefficients[3] = 2.75;
    expected_coefficients[4] = 12;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;

    }
    
    printPolynomial(pol1);
    printf("+\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);
    
    
    printf("\naddPolynomials: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = -0.33;
    coefficients1[1] = 2;
    coefficients1[2] = -0;
    coefficients1[3] = -2.2;
    coefficients1[4] = 1;
    pol1 = createPolynomial(coefficients1, 5);
    
    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = -5.3;
    coefficients2[1] = -1;
    coefficients2[2] = 2;
    coefficients2[3] = 0;
    coefficients2[4] = -5;
    pol2 = createPolynomial(coefficients2, 5);
    
    result = addPolynomials(pol1,pol2);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.63;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 2;
    expected_coefficients[3] = -2.2;
    expected_coefficients[4] = -4;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;

    }
    
    printPolynomial(pol1);
    printf("+\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);
    
    
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    free(pol1);
    free(pol2);
    free(result);
    
    return ret;
}

int testSubtraction()
{
    double threshhold = 0.001;
    double* coefficients1;
    double* coefficients2;
    double* expected_coefficients;
    polynomial* pol1;
    polynomial* pol2;
    polynomial* result;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\nsubtractPolynomials: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = -5.44;
    coefficients2[1] = -123;
    coefficients2[2] = -5.5;
    coefficients2[3] = -0.22;
    coefficients2[4] = -0;
    pol2 = createPolynomial(coefficients2, 5);
    
    result = subtractPolynomials(pol1,pol2);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 8.04;
    expected_coefficients[1] = 124;
    expected_coefficients[2] = 11.27;
    expected_coefficients[3] = 2.75;
    expected_coefficients[4] = 12;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;

    }
    
    printPolynomial(pol1);
    printf("-\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);
    
    
    printf("\nsubtractPolynomials: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = -0.33;
    coefficients1[1] = 2;
    coefficients1[2] = -0;
    coefficients1[3] = -2.2;
    coefficients1[4] = 1;
    pol1 = createPolynomial(coefficients1, 5);
    
    coefficients2 = malloc(sizeof(double) * 5);
    coefficients2[0] = 5.3;
    coefficients2[1] = 1;
    coefficients2[2] = -2;
    coefficients2[3] = -0;
    coefficients2[4] = 5;
    pol2 = createPolynomial(coefficients2, 5);
    
    result = subtractPolynomials(pol1,pol2);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.63;
    expected_coefficients[1] = 1;
    expected_coefficients[2] = 2;
    expected_coefficients[3] = -2.2;
    expected_coefficients[4] = -4;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
            // return 0 means there was an error
            ret = 0;

    }
    
    printPolynomial(pol1);
    printf("-\n");
    printPolynomial(pol2);
    printf("=\n");
    printPolynomial(result);
    
    
    free(expected_coefficients);
    free(coefficients1);
    free(coefficients2);
    free(pol1);
    free(pol2);
    free(result);
    
    return ret;
}
