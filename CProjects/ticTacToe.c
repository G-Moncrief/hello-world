/*
 *	Garrett Moncrief
 *
 *  Tic Tac Toe game 
 *	Steps:
 *	1.)	Each game starts by clearing and reset the board/round counter
 *	2.)	After game is started game will run until there is a winner or 9 rounds pass
 *	3.)	After game user will be prompted to play again
 *
 * 	Additional information commented below
 *
 */
 
#include <stdio.h>
#include <stdbool.h>
#define N 9

int checkForWinner(char *);
void printBoard (char *);
void resetBoard (char *);
bool goAgain ();

int main ()
{
	char board[N];
	int player; //determines what player's turn it is
	int round; //tracks the number of rounds...helps determine if tie 
	int playerTurn; //toggles to indicate when turn is completed
	int winner; //toggles to indicate when a game is ongoing and who winner is
	bool replay; //asks user if wants to play again
	int row, col; //placeholder for user row/col selection
	int sel; //user selection...uses row and col to determine array element
	char *p; //pointer
	char ecksOrOhhs; //toggles between X's and O's based on player
	
	
	do //start of game, will return here if player opts to play again...resets board  
	{
		resetBoard(board); 
		winner = 0;
		round = 1;
		while (winner == 0) //if a winner has not been established returns here
		{
			printBoard(board);
			playerTurn = 1;
			player = ( round%2 != 0 ? 1 : 2); //player 1 goes on odd rounds, player 2 goes on even rounds 
			printf ("\nCurrent Move: Player %d", player);
			//chooses whether token is an X or an O
			if (player == 1)
				ecksOrOhhs = 'X';
			else
				ecksOrOhhs = 'O';
			do//beginning of each player's turn
			{
				printf("\nEnter Row (0-2): ");
				scanf ("%d", &row);
				printf("Enter Column (0-2): ");
				scanf ("%d", &col);
				sel = (row*3 + col);//sel is row *3 ie 0,3,6 and + col 0,1,2...vals outside 0-8 give error
				if (sel < 0 || sel > 8 || col < 0 || col > 2)
				{
					printf ("Invalid selection, please try again.");
				}
				else 
				{
					p=board+sel;
					if (*p == ' ')//checks to make sure the space is empty if not else prompts error 
					{
						*p = ecksOrOhhs;
						winner = checkForWinner(board);
						playerTurn = 0;//toggles valid move to break out of do while loop 
						break;
					}
					else
					{
						printf ("Invalid selection, please try again.");
					}
				}
			}while (playerTurn ==1);//will loop until valid move is made 

			if (winner == 1)
			{
				printBoard(board);
				printf ("\n**** Player %d wins! ****\n", player);
				break;
			}
			
			round++;
			
			if (round == 10)
			{
				printBoard(board);
				winner =1;
				printf ("\n**** The game has ended in a draw ****\n");
				break;
			}
		}
		
		replay = goAgain();
	}while (replay==true);
	
	return 0;
}


//asks the player if they want to play again...result toggles bool at end of main do loop
bool goAgain()
{
	char temp;
	printf("\nWould you like to play another game(y/n)? ");
	scanf ("%c", &temp);
	while (temp != 'n' && temp != 'N' && temp != 'y' && temp != 'Y') 
	{
		scanf("%c", &temp);
	}
	if (temp == 'y' || temp == 'Y') 
	{
		return true;
	} 
	else 
	{
    return false;
	}
}

//resets the board to all blank spaces after each round 
void resetBoard(char *board)
{
	char *p;
    for (p = board; p < board+N; p++) 
       *p = ' ';
}

//prints and formats the board
void printBoard(char *board) 
{
	char *p;
	printf("\n\n");
	p=board;
	printf (" %c", *p);
	for (p=board+1; p < board+3; p++)
       printf(" | %c", *p);
   printf("\n---+---+---\n %c", *p);
   	for (p=board+4; p < board+6; p++)
       printf(" | %c", *p);
   printf("\n---+---+---\n %c", *p);
   for (p=board+7; p < board+N; p++)
       printf(" | %c", *p);
       
   printf("\n\n");
}

//checks if three in a row for each player based on diag, horiz, vert win conditions
int checkForWinner (char *board)
{
	//diagonals 
	if (*(board) == 'X' && *(board+4)== 'X' && *(board+8)=='X') 
		return 1;
	else if (*(board) == 'O' && *(board+4)== 'O' && *(board+8)=='O') 
		return 1;
	else if (*(board+2) == 'X' && *(board+4)== 'X' && *(board+6)=='X') 
		return 1;
	else if (*(board+2) == 'O' && *(board+4)== 'O' && *(board+6)=='O') 
		return 1;
	//horizontal rows
	else if(*(board) == 'X' && *(board+1)== 'X' && *(board+2)=='X') 
		return 1;
	else if(*(board) == 'O' && *(board+1)== 'O' && *(board+2)=='O') 
		return 1;
	else if(*(board+3) == 'X' && *(board+4)== 'X' && *(board+5)=='X')
		return 1;
	else if(*(board+3) == 'O' && *(board+4)== 'O' && *(board+5)=='O')
		return 1;
	else if(*(board+6) == 'X' && *(board+7)== 'X' && *(board+8)=='X')
		return 1;
	else if(*(board+6) == 'O' && *(board+7)== 'O' && *(board+8)=='O')
		return 1;
	//vert cols
	else if(*(board) == 'X' && *(board+3)== 'X' && *(board+6)=='X') 
		return 1;
	else if(*(board) == 'O' && *(board+3)== 'O' && *(board+6)=='O') 
		return 1;
	else if(*(board+1) == 'X' && *(board+4)== 'X' && *(board+7)=='X') 
		return 1;
	else if(*(board+1) == 'O' && *(board+4)== 'O' && *(board+7)=='O') 
		return 1;
	else if(*(board+2) == 'X' && *(board+5)== 'X' && *(board+8)=='X') 
		return 1;
	else if(*(board+2) == 'O' && *(board+5)== 'O' && *(board+8)=='O') 
		return 1;
	//otherwise no winner
	else 
		return 0;
}