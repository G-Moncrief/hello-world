/*
	FIZZBUZZ
	
	For numbers 1 - 100 if number is a mult of 3 prints FIZZ
	if number is a mult of 5 prints BUZZ if number is a mult 
	of 15 prints FIZZBUZZ

*/

#include <stdio.h>

int main (void)
{
	for (int i = 1; i <= 100; i++)
	{
		if (i%15==0)
			printf("FIZZBUZZ\n");
		else if (i%3 == 0)
			printf("FIZZ\n");
		else if (i%5 == 0)
			printf("BUZZ\n");
		else printf ("%d\n", i);
	}
	return 0;
}