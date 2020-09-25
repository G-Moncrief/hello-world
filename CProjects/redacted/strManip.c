/*
 *	Garrett Moncrief
 *
 *	This will be the file all the string manipulations happen in 
 *
 *	Further exp. of what functions do commented above the functions below
 *
 */

#include <stdio.h>
#include <string.h>
#include "strManip.h"




//gets the number of characters in the string 
int charCounter (char *string) 
{
	int len = strlen(string);
	return len;
}

//gets the number of words in the string 
int wordCounter (char *stringCpy)
{
	char *p;
	char *delim = " \t\r\n\f";
	int count = 0;
	
	for (p = strtok(stringCpy, delim); p != NULL; count++)
		p = strtok(NULL, delim);
	
	return count;
}

//REDACTS values from input txt 
void redactMatic (char *string, char *replacementWord)
{
	char *p1;
	char *p2;
	char red[] = "###REDACTED###";
	char replace [3000];
	
	
	
		if (strstr(string,replacementWord)) //checks to see if word to redact is present
		{
			p2 = string; //sets pointer 2 to beginning of string 
			
			while ((p1 = (strstr(p2, replacementWord))))
			{
				*p1 = '\0';
				strcpy (replace,p2); //copies up to the \0
		
				p1 = p1 + strlen(replacementWord); //moves pointer 1 to the end of replace word 
				strcat (replace, red); //writes ###REDACTED###
				p2 = p1; //move pointer 2 to pointer 1 pos
				
				strcat (replace, p1); 
				strcpy (string, replace);
			}
		}
	
}