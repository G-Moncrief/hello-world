//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;

//This program will ask the user how many verses of the song "100 bottles of beer" they would like to endure

public class TravelingSong

{
   public static void main(String[] args)
   
   {
   //declare var
   
   int bottlesBeer, numberVerses, check;
   
   //set up input object...ask user for a value from 1-100
   
   Scanner input = new Scanner(System.in);
   
   System.out.println ("This program will regale you with verses from the travelling song \"One Hundred Bottles of Beer.\"\n");
   
   System.out.print ("Enter the number of verses that you would like output (from 1-100): ");
   numberVerses = input.nextInt();
   
   //give an invalid response if answer isn't in the 1-100 range and prompt user to input again
   
   while (numberVerses < 1 || numberVerses > 100)
   
      {
      System.out.print ("\nInvalid input. \n\nEnter the number of verses that you would like output (from 1-100): ");
      numberVerses = input.nextInt();
      }
      
   bottlesBeer = 100;
   
   //for loop that as long as the number of requested verses is greater than the number of iterations that have passed
   //the program will run, increasing the check value and decreasing the bottlesBeer value w/ each iteration
   
   for (check = 0; check < numberVerses; check++)
      {
            System.out.print ("\n" +bottlesBeer + " bottles of beer on the wall.\n" + bottlesBeer + " bottles of beer." 
            + "\nIf one of those bottles should happen to fall.\n" + (bottlesBeer-1) +" bottles of beer on the wall.\n");
            bottlesBeer -- ;
    
      }    
      
   }
    
}