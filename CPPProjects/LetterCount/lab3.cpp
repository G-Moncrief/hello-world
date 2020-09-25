#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

#include "lettercount.h"

void anagramTime(LetterCount &incoming);

vector <char*> dixList;
vector <LetterCount*>dixLC;
char chkWord[2000];
vector <int> gramWords;

bool found = false;

main()
{
	ifstream dix("dictionary.txt");
	
	if (dix.is_open())
	{
		string dixWord;
		
		//building the vectors for dixList and dixLC
		while (dix >> dixWord)
		{
			char *a = new char [dixWord.size()+1];
			dixList.push_back(a);
			memcpy(a, dixWord.c_str(), dixWord.size()+1);
			LetterCount* countAdd = new LetterCount (a);
			dixLC.push_back(countAdd);
		}
		
		//get user input
		cout << "\n\nEnter a word to find anagrams: ";
		cin.getline(chkWord, 2000);
		LetterCount input(chkWord);
		
		cout << "\n\nSome anagrams for " << chkWord << " are: \n_____________________________\n\n";
		
		//goes through the dictionary...if an exact match it outputs entire word
		for (int i = 0; i < dixList.size(); i++)
		{
			if (input.equals(*dixLC[i]))
			{
				cout << "\n" << dixList[i] << "\n";
				found = true;
			}
			//if partial match it makes a copy and adds the word to the anagrams vector then subtracts the LC
			//then sends to function to look for more words
			else if (input.hasAsMany(*dixLC[i]))
			{
				gramWords.clear();
				LetterCount copy(input);
				copy.subtract(*dixLC[i]);
				gramWords.push_back(i);
				anagramTime(copy);
			}
		}
		
		//gives a message if no anagrams were found
		if (found == false)
			cout << "No anagrams found :( \n\n";
	}
	//if there is a problem opening the file
	else
	{
		cout << "There was a problem opening the dictionary file.";
	}
	
	return 0;
}

void anagramTime(LetterCount &incoming)
{	
	//cycles through the dictionary, if an exact match is found it is printed
	for (int i = 0; i < dixList.size(); i++)
	{
		if (incoming.equals(*dixLC[i]))
		{
			gramWords.push_back(i);
			for (int j = 0; j < gramWords.size();j++)
			{
				cout << dixList[gramWords[j]] << " ";
			}
			cout << "\n";
			found = true;
		}
		
		//if a partial match is found it is added to the anagrams vector and subtracted from the word 
		//then sends it back through anagramTime to find more words
		if (incoming.hasAsMany(*dixLC[i]))
		{
			gramWords.push_back(i);
			incoming.subtract(*dixLC[i]);
			anagramTime(incoming);
		}	
	}
}
