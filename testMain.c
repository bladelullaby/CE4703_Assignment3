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
    
    if(testMultiplication() == 1)
        printf("multiplyPolynomial tested: OK\n");
    else
        printf("multiplyPolynomial tested: ERROR\n");
    
    if(testDivision() == 1)
        printf("dividePolynomial tested: OK\n");
    else
        printf("dividePolynomial tested: ERROR\n");
    
    if(testNormalization() == 1)
        printf("normalizePolynomial tested: OK\n");
    else
        printf("normalizePolynomial tested: ERROR\n");
        
    if(testGetOrder() == 1)
        printf("getPolynomialOrder tested: OK\n");
    else
        printf("getPolynomialOrder tested: ERROR\n");
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
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }

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
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }

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
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }

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
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }

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


int testMultiplication()
{
    double threshhold = 0.001;
    double factor;
    double* coefficients1;
    double* expected_coefficients;
    polynomial* pol1;
    polynomial* result;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\nmultiplyPolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    factor = -2.1;
    
    result = multiplyPolynomial(pol1, factor);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -5.46;
    expected_coefficients[1] = -2.1;
    expected_coefficients[2] = -12.117;
    expected_coefficients[3] = -5.313;
    expected_coefficients[4] = -25.2;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }
    }
    
    printPolynomial(pol1);
    printf("*\n");
    printf("%lf\n",factor);
    printf("=\n");
    printPolynomial(result);
    
    
    
        printf("\nmultiplyPolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    factor = -0;
    
    result = multiplyPolynomial(pol1, factor);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 0;
    expected_coefficients[1] = 0;
    expected_coefficients[2] = 0;
    expected_coefficients[3] = 0;
    expected_coefficients[4] = 0;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }
    }
    
    printPolynomial(pol1);
    printf("*\n");
    printf("%lf\n",factor);
    printf("=\n");
    printPolynomial(result);
    
    
    
    free(expected_coefficients);
    free(coefficients1);
    free(result);
    
    return ret;
}


int testDivision()
{
    double threshhold = 0.001;
    double factor;
    double* coefficients1;
    double* expected_coefficients;
    polynomial* pol1;
    polynomial* result;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\ndividePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = -5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    factor = 10;
    
    result = dividePolynomial(pol1, factor);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = 0.26;
    expected_coefficients[1] = 0.1;
    expected_coefficients[2] = -0.577;
    expected_coefficients[3] = 0.253;
    expected_coefficients[4] = 1.2;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }
    }
    
    printPolynomial(pol1);
    printf("/\n");
    printf("%lf\n",factor);
    printf("=\n");
    printPolynomial(result);
    
    
    
        printf("\ndividePolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 2.6;
    coefficients1[1] = 1;
    coefficients1[2] = 5.77;
    coefficients1[3] = 2.53;
    coefficients1[4] = 12;
    pol1 = createPolynomial(coefficients1, 5);
    
    factor = -0.05;
    
    result = dividePolynomial(pol1, factor);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -52;
    expected_coefficients[1] = -20;
    expected_coefficients[2] = -115.4;
    expected_coefficients[3] = -50.6;
    expected_coefficients[4] = -240;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }
    }
    
    printPolynomial(pol1);
    printf("/\n");
    printf("%lf\n",factor);
    printf("=\n");
    printPolynomial(result);
    
    
    
    free(expected_coefficients);
    free(coefficients1);
    free(result);
    
    return ret;
}

int testNormalization()
{
    double threshhold = 0.001;
    double* coefficients1;
    double* expected_coefficients;
    polynomial* pol1;
    polynomial* result;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\nnormalizePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 1;
    coefficients1[1] = 2;
    coefficients1[2] = -3;
    coefficients1[3] = -4;
    coefficients1[4] = -5;
    pol1 = createPolynomial(coefficients1, 5);
    
    
    result = normalizePolynomial(pol1);
    
    expected_coefficients = malloc(sizeof(double) * 5);
    expected_coefficients[0] = -0.2;
    expected_coefficients[1] = -0.4;
    expected_coefficients[2] = 0.6;
    expected_coefficients[3] = 0.8;
    expected_coefficients[4] = 1;
    
    for(int i = 0; i < 5; i++)
    {
        if(!equal(result->coefficients[i], expected_coefficients[i], threshhold))
        { // return 0 means there was an error
            ret = 0;
            printf("%lf != %lf\n",result->coefficients[i],expected_coefficients[i]);
        }
    }
    
    printPolynomial(pol1);
    printf("->\n");
    printPolynomial(result);
    
    
    
    free(expected_coefficients);
    free(coefficients1);
    free(result);
    
    return ret;
}

int testGetOrder()
{
    double* coefficients1;
    int expected_order;
    polynomial* pol1;
    int order;
    // return 1 means all ok
    int ret = 1;
    
    
    printf("\nnormalizePolynomial: test 1\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 1;
    coefficients1[1] = 2;
    coefficients1[2] = -3;
    coefficients1[3] = -4;
    coefficients1[4] = 0;
    pol1 = createPolynomial(coefficients1, 5);
    
    
    order = getPolynomialOrder(pol1);
    
    expected_order = 3;
    
    for(int i = 0; i < 5; i++)
    {
        if(order != expected_order)
        { // return 0 means there was an error
            ret = 0;
            printf("%d != %d\n",order,expected_order);
        }
    }
    
    printPolynomial(pol1);
    printf("->\n");
    printf("order: %d\n",order);
    
    
    printf("\nnormalizePolynomial: test 2\n");
    coefficients1 = malloc(sizeof(double) * 5);
    coefficients1[0] = 0;
    coefficients1[1] = 0;
    coefficients1[2] = 0;
    coefficients1[3] = 0;
    coefficients1[4] = 0;
    pol1 = createPolynomial(coefficients1, 5);
    
    
    order = getPolynomialOrder(pol1);
    
    expected_order = 0;
    
    for(int i = 0; i < 5; i++)
    {
        if(order != expected_order)
        { // return 0 means there was an error
            ret = 0;
            printf("%d != %d\n",order,expected_order);
        }
    }
    
    printPolynomial(pol1);
    printf("->\n");
    printf("order: %d\n",order);
    
    
    free(coefficients1);
    
    return ret;
}
