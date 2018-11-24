// interface.c
// Unit 3 Assignment
// A text based user interface that takes user input,
//
// Author: Eoin Flynn
// Student ID: 15179818
// Date: 10.11.2018

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize variables
    int menu, equation, storage;

    do
    {
        printf("Please select from the following options: \n");
        printf("1) Create a polynomial\n");
        printf("2) Delete a polynomial\n");
        printf("3) View stored polynomials\n");
        printf("4) Do equations with stored polynomials\n");
        printf("5) Exit!\n"); //exit function enabled by a do-while loop: do while != 4
        printf("You have selected: ");
        scanf("%i", &menu);   //reads user input
        // a way to have a case that allows "Return to main menu"?

        switch (menu) //text based user interface
        {
        case 1: //1) Create a polynomial
            //fill in details for polynomial here
            break;

        case 2: //2) Delete a polynomial
            //display list of stored polynomials to select which to delete
            break;

        case 3: //3) View stored polynomials
            do
            {
                //display list of stored polynomials
                printf("1) Exit!\n");
                printf("List of stored polynomials: \n");
                printf("You have selected: ");
                scanf("%i", &storage);

                switch (storage)
                {
                case 1:
                    break;
                }
            } while (storage != 1);
            break;

        case 4: //4) Do equations with stored polynomials
            do
            {
                printf("Please select from the equations below: \n");
                printf("1) Add two polynomials\n");
                printf("2) Subtract two polynomials\n");
                printf("3) Multiplication of a polynomial by a double\n");
                printf("4) Division of a polynomial by a double\n");
                printf("5) Normalisation of a polynomial\n");
                printf("6) Return order of a polynomial\n");
                printf("7) Print polynomial to stdout\n");
                printf("8) Exit!\n");
                printf("You have selected: ");
                scanf("%i", &equation);

                switch (equation)
                {
                case 1: //Add two polynomials
                        printf("Add two polynomials\n");
                    break;

                case 2: //Subtract two polynomials
                        printf("Subtract two polynomials\n");
                    break;

                case 3: //Multipy a polynomial by a double
                        printf("Multipy a polynomial by a double\n");
                    break;

                case 4: //Divide a polynomial by a double
                        printf("Divide a polynomial by a double\n");
                    break;

                case 5: //Normailise a polynomial
                        printf("Normailise a polynomial\n");
                    break;

                case 6: //Return order of a polynomial
                        printf("Return order of a polynomial\n");
                    break;

                case 7: //Print polynomial to stdout
                        printf("Print polynomial to stdout\n");
                    break;
                }
                break;
            } while (equation != 8);

            default:
                printf("ERROR: invalid input\n");
                //  return main();
                break;
        }
    } while (menu != 5); //have the number != to the number relevant to "Exit"

    return 0;
}
