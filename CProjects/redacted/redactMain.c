/*
 *	Garrett Moncrief
 *
 *	This program reads input from a txt file, counts the characters, words, and 
 *	censors words input at the command line from the input txt. These are then output
 *	to an output txt file to be specified by user.
 *
 *	Main calls on the functions and performs the tasks of opening the input file 
 *	and writing to output file 
 *
 */
 
#include <stdio.h>
#include <string.h>
#include "fileUtils.h"
#include "strManip.h"

int main (int argc, char *argv[])
{
	char *inputFilename = argv[1];
	char *outputFilename = argv[2];
	
	char string[MAX_CHAR_COUNT]; 
	char stringCpy[MAX_CHAR_COUNT];//used this as work around for word count messing up orig string
	char replacementWord[MAX_CHAR_COUNT]; //used to pass argv[whatever] to strManip.c
	
	int numChars = 0;
	char numCharStr[MAX_CHAR_COUNT]; //used to build sprintf
	int numWords = 0;
	char numWordsStr[MAX_CHAR_COUNT]; //used to build sprintf
	
	
	//make sure correct number of command line arguments 
	
	if (argc < 3)
	{
		printf("Missing input parameters\n");
		printf("Program usage: %s <input filename> <output filename> <redacted word(s)>\n\n",argv[0]);
		return -1;
	}
	
	
	int status = readFromFile(string, inputFilename);
	
	//read input file to string 
	switch(status)
	{
		case FILE_OPEN_ERROR:
			printf("Error opening %s\n", inputFilename);
			break;
		case FILE_READ_ERROR:
			printf("Error reading %s\n", inputFilename);
			break;
		default:
		//display contents of file in terminal
		printf("\n\n===Read From file %s:===\n\n %s \n", inputFilename, string);
	}
	
	strcpy (stringCpy, string); //did this because wordCounter was messing up orig string
	
	numChars = charCounter (string); //gets the number of characters 
	sprintf(numCharStr, "NUMBER OF CHARACTERS: %d",numChars);
	
	numWords = wordCounter (stringCpy);
	sprintf(numWordsStr, "\n\nNUMBER OF WORDS: %d\n\n",numWords);
	
	for (int i = 3; i < argc; i++)
	{
		strcpy (replacementWord, argv[i]);
		redactMatic (string, replacementWord);
	}
	
	//write output 
	status = writeToFile (numCharStr, outputFilename, OVERWRITE_FILE);
	writeToFile (numWordsStr, outputFilename, APPEND_FILE);
	writeToFile (string, outputFilename, APPEND_FILE);
		switch(status)
	{
		case FILE_OPEN_ERROR:
			printf("Error opening %s\n", outputFilename);
			break;
		case FILE_WRITE_ERROR:
			printf("Error reading %s\n", outputFilename);
			break;
		case FILE_WRITE_INVALID_MODE:
			printf("Invalid write mode for %s\n", outputFilename);
			break;
		default:
		//display contents of file in terminal
		printf("\n===Wrote to %s:===\n\n%s%s%s \n", outputFilename, numCharStr, numWordsStr,string);
	}
	
	return 0;
}


