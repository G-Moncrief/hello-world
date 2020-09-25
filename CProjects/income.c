/* 
 *	Program accepts input from user for the number of hours worked and their hourly pay rate
 *
 *	If user has worked in excess of 40 hours normal income will be calculated as base pay
 *	multiplied by 40 and additional hours worked will be calculated at time and a half.
 *
 */

#include <stdio.h>
#define TAX_RATE 0.15

int main(void)
{
	float  hoursWorked, payRate, taxWithheld, normalInc, overTime = 0;
	
	printf ("\n\nEnter number of hours worked: ");
	scanf ("%f", &hoursWorked);
	
	printf ("Enter hourly pay rate: $");
	scanf ("%f", &payRate);
	
	if (hoursWorked <= 40)
		normalInc = hoursWorked * payRate;
	
	else 
	{
		normalInc = payRate * 40;
		overTime = (hoursWorked - 40) * (payRate * 1.5);
	}
	
	taxWithheld = (normalInc + overTime) * TAX_RATE;
	
	printf ("\nDescription\t\t\t     Amount\n");
	printf ("-------------------------------------------\n");
	printf ("Normal Income:\t\t\t $ %8.2f\n", normalInc);
	printf ("Overtime Income:\t\t $ %8.2f\n", overTime);
	printf ("Taxes Withheld:\t\t\t $ %8.2f\n", taxWithheld);
	printf ("-------------------------------------------\n");
	printf ("Net Income:\t\t\t $ %8.2f\n\n", normalInc + overTime - taxWithheld);
	
	return 0;
	
}
