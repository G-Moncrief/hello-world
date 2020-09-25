/*	Garrett Moncrief
 *
 *		This is a matrix function calculator that accepts user input for two matrices
 *		up to 5x5 and then prompts user if they would like to view, add, mult, or quit
 *
 */

#include <stdio.h>

int main (void)
{
	int rowsA, colsA, rowsB, colsB, i, j, k, userSel = 1;
	double prodSum;
	
	printf ("\n\n\nMatrix Math Calculator\n\n");
	printf ("This program computes the sum and product of two matrices up to 5 x 5 ");
	printf ("in size. Please begin by specifying each matrix's dimensions and input.");
	
	/*	===Matrices Setup===
	 *	Matrices are indexed using the typical nested for functions for multi-D arrays.
	 *
	 *	Per project specifications program accepts dimension size up to 5...as such
	 *	while loops are included after each scanf function to ensure that input is 
	 *	within the specifications. 
	 */
	printf ("\n\n--------------\nFor Matrix A:\n--------------");
	printf ("\n\nHow many rows? ");
	scanf ("%d", &rowsA);
	while ((rowsA > 5) || (rowsA < 1))
	{
		printf("Valid dimension size is between 1 and 5, please try again: ");
		scanf ("%d", &rowsA);
	}
	printf ("How many columns?  ");
	scanf ("%d", &colsA);
	while ((colsA > 5) || (colsA < 1))
	{
		printf("Valid dimension size is between 1 and 5, please try again: ");
		scanf ("%d", &colsA);
	}
	double matrixA[rowsA][colsA];
	
	//matrixA indexing code starts below 
	printf ("\nEnter %d values for row 1: ", colsA);
	for (i = 0; i < rowsA; i++)
	{
		for (j = 0; j < colsA; j++)
			scanf ("%lf", &matrixA[i][j]);
		(i < rowsA - 1) ? printf("\nEnter %d values for row %d: ", colsA, i+2) : printf ("\n");
	}
	
	//matrixB setup starts below
	printf ("\n--------------\nFor Matrix B:\n--------------");	
	printf ("\n\nHow many rows? ");
	scanf ("%d", &rowsB);
	while ((rowsB > 5) || (rowsB < 1))
	{
		printf("Valid dimension size is between 1 and 5, please try again: ");
		scanf ("%d", &rowsB);
	}
	printf ("How many columns?  ");
	scanf ("%d", &colsB);
	while ((colsB > 5) || (colsB < 1))
	{
		printf("Valid dimension size is between 1 and 5, please try again: ");
		scanf ("%d", &colsB);
	}
	double matrixB[rowsB][colsB];
	
	//matrixB indexing code starts below
	printf ("\nEnter %d values for row 1: ", colsB);
	for (i = 0; i < rowsB; i++)
	{
		for (j = 0; j < colsB; j++)
			scanf ("%lf", &matrixB[i][j]);
		(i < rowsB - 1) ? printf("\nEnter %d values for row %d: ", colsB, i+2) : printf ("\n");
	}
	
	/*	===User Menu===
	 *	The user menu will prompt the user to make a selection after each operation until 
	 *	they choose 0 to quit. If an invalid selection is chosen a default error message 
	 *	will prompt user to choose a valid option.
	 *
	 *	All output is to the third decimal and justified to eight digits. Very large or small
	 *	numbers may result in formatting issues.
	 *
	 *	Add/Mult functions include if/else function to ensure that valid matrix operation is
	 *	being performed...prints error message if matrix dimensions are incorrect for funct.
	 */
	 while (userSel != 0)
	 {
		printf ("\n\n*************************");
		printf ("\n* 1 - View Matrices     *");
		printf ("\n* 2 - Add Matrices      *");
		printf ("\n* 3 - Multiply Matrices *");
		printf ("\n* 0 - Quit              *");
		printf ("\n*************************");
		printf ("\n\nPlease enter selection: ");
		scanf ("%d", &userSel);
		
		switch(userSel)
		{
			case 1: 
			{
				printf ("\n\nMatrix A:\n\n");
				for (i = 0; i < rowsA; i++)
				{
					for (j = 0; j < colsA; j++)
						printf ("\t%8.3lf", matrixA[i][j]);
					printf ("\n");
				}
				
				printf ("\n\nMatrix B:\n\n");
				for (i = 0; i < rowsB; i++)
				{
					for (j = 0; j < colsB; j++)
						printf ("\t%8.3lf", matrixB[i][j]);
					printf ("\n");
				}
				break;
			}
			
			case 2:
			{
				if ((rowsA == rowsB) && (colsA == colsB))
				{
					printf ("\n\nSum of Matrices:\n\n");
					for (i =0; i < rowsA; i++)
					{
						for (j = 0; j < colsA; j++)
							printf ("\t%8.3lf", matrixA[i][j]+matrixB[i][j]);
						printf("\n");
					}
				}
				else
				{
					printf ("\n      - - Unable to complete operation - - ");
					printf ("\nTo be added together matrices must have same dimensions.");	
				}
				break;
			}
			
			case 3: 
			{
				if (colsA == rowsB)
				{
					printf("\n\nProduct of Matrices:\n\n");
					for (i = 0; i < rowsA; i++)
					{
						for (j = 0; j < colsB; j++)
						{
							prodSum = 0;
							for (k =0; k < colsA; k++)
								prodSum = prodSum + matrixA [i][k] * matrixB [k][j];
							printf("\t%8.3lf", prodSum);
						}
						printf ("\n");
					}
				}
				else
				{
					printf ("\n      - - Unable to complete operation - - ");
					printf ("\nTo be multiplied, the number of columns in Matrix A must");
					printf ("\n      match the number of rows in Matrix B.");
				}
				break;
			}
		
			case 0:
			{
				printf ("\n\n\n ***Goodbye!***\n\n\n");
				break;
			}
			
			default:
			{
				printf ("Invalid Selection. Try again or enter 0 to quit.");
				break;
			}
			
		}
	}
	 
	return 0;
}
