// visualization.c
// Unit 3 Group Assignment
/*
Description: 
Provide a loop to print output in the correct polynomial format
Use if-else statements in order to specify when each part is printed
This controls the format in the desired way, giving an output like the example below
When the length of polynomial is reached then it will end the foor loop

Example of output: 
addPolynomials: test 1
12.000000 * x^(4) + 2.530000 * x^(3) + 5.770000 * x^(2) + 1.000000 * x + 2.600000
+
0.000000 * x^(4) + 0.220000 * x^(3) + 5.500000 * x^(2) + 123.000000 * x + 5.440000
=
12.000000 * x^(4) + 2.750000 * x^(3) + 11.270000 * x^(2) + 124.000000 * x + 8.040000

Group:
Group 08
Members: Eoin Flynn 15179818, James Duffy 17206286, 
Darragh O'Donnel 17239567, Joshua Geraghty 17201276, 
Gabriel Scheibler 18082882
Date: 26/11/18
*/



#include "visualization.h" // include header file

void printPolynomial(polynomial* pol) // function that returns void and takes in a polynomial
{
    
    for (int i = pol->length - 1; i >= 0; i--)  // initialize loop variable i, pol pointer length - 1 is the condition, i can only be >= 0, increment i--
    {
        if(i != (pol->length - 1))  // prints i so long as it does't equal (pol->length -1)
        {
            printf(" + "); // prints +
        }
        if(i != 0 && i != 1) // only printing i when it is 4, 3, then 2 and not when it is equal to 0 and 1
        {
            printf("%lf * x^(%d)", pol->coefficients[i], i); // prints double from coefficients array and interger i, in shown format
        }
        else if(i == 1) // i equals 1
        {
            printf("%lf * x", pol->coefficients[i]); // prints double from coefficients array, in shown format
        }
        else // this prints if it doesn't satisfy the other statements
        {
            printf("%lf", pol->coefficients[i]); // prints double from coefficients array
        }
    }
    
    printf("\n"); // print \n to go down a line
}
