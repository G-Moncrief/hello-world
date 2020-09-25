/*	Garrett Moncrief
 *
 *
 *
 *
 */


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LEN 15
#define MAX_NUM_EMPLOYEES 10
#define TAX_RATE 0.15f
#define FULL_TIME 40
#define OVERTIME_RATE_MULTIPLIER 1.5f

struct employee
{
	char name[MAX_NAME_LEN];
	int id;
	double hoursWorked;
	double hourlyRate;
	double netInc;
	double lessTax;
	struct employee *next;
};

struct employee* buildEmployeeList(char* filename);
int writeSalaryInfoToFile(struct employee* listHead, char* filename);

struct employee *listHead=NULL; //points to the first part


#endif //EMPLOYEE_H