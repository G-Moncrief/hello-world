/*
 *	Garrett Moncrief
 *
 *	This program takes an input file with the employee name, id number, hrs worked, and hrly payrate
 *	and computes the net amount the employee has earned and the taxes taken out. This information is 
 *	then output to a .txt file. Futher comments on individual functions 
 */

#include <stdio.h>
#include "employee.h"


//builds the struct (including calculating the net income and tax withheld)
int buildEmployeeList (FILE *fp, struct employee list[])
{
	int count = 0;//will be used to calc the number of employees
	int i = 0;
	double gross; //used to calc net income and tax withheld
	
	//until EOF is reached fscan plugs values into struct members while count++ adds number of employees 
	while (EOF!=fscanf(fp, "%s %d %lf %lf\n", list[i].name,&list[i].id,&list[i].hrsWorked,&list[i].hrlyRate))
	{
		i++;
		count++;
	}
	
	//uses hrs worked to det if employee is elig for overtime...plugs values into struct members 
	for (i = 0; i < count; i++)
	{
		if (list[i].hrsWorked >= FULL_TIME) 
		{
			gross = ((list[i].hrsWorked - FULL_TIME) * (list[i].hrlyRate * OVERTIME_RATE_MULTIPLIER)) + (FULL_TIME * list[i].hrlyRate);
			list[i].lessTax = gross * TAX_RATE;
			list[i].netInc = gross - (list[i].lessTax);
		}
		
		else
		{
			gross = list[i].hrsWorked * list[i].hrlyRate;
			list[i].lessTax = gross * TAX_RATE;
			list[i].netInc = gross - (list[i].lessTax);
		}
	}
	
	return count;
}

//after struct members filled out this funct writes to the output file...doubles are taken to 2 dec places
void writeSalaryInfoToFile (FILE *fw, struct employee list[], int numEmp)
{
	for (int i = 0; i < numEmp; i++)
	{
		fprintf(fw,"%s,%d,%0.2lf,%0.2lf\n", list[i].name,list[i].id,list[i].netInc,list[i].lessTax);
	}
	
}
