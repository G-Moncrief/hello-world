//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;

//This program will determine the chinese zodiac user was born under based off birth year
public class ChineseZodiac

{
   public static void main(String[] args)
   {
   //declare var
   
   int inputYear, remYear;
   
   //set up input object
   
   Scanner input = new Scanner(System.in);
   
   System.out.println ("This program will tell you what Chinese Zodiac you were born under.\n");
   
   System.out.print ("Enter the year that you were born: ");
   inputYear = input.nextInt();
   
   //switch function based off the remainder of a modulus operator year%12
   
   remYear = inputYear%12;
   
   switch (remYear)
    {
   
      case 0:
      System.out.print ("\n" +inputYear +" was the year of the Monkey");
      break;
      
      case 1:
      System.out.print ("\n" +inputYear +" was the year of the Rooster");
      break;      
      
      case 2:
      System.out.print ("\n" +inputYear +" was the year of the Dog");
      break;
      
      case 3:
      System.out.print ("\n" +inputYear +" was the year of the Pig");
      break;
      
      case 4:
      System.out.print ("\n" +inputYear +" was the year of the Rat");
      break;      
      
      case 5:
      System.out.print ("\n" +inputYear +" was the year of the Ox");
      break;  
      
      case 6:
      System.out.print ("\n" +inputYear +" was the year of the Tiger");
      break;
      
      case 7:
      System.out.print ("\n" +inputYear +" was the year of the Rabbit");
      break;      
      
      case 8:
      System.out.print ("\n" +inputYear +" was the year of the Dragon");
      break;
      
      case 9:
      System.out.print ("\n" +inputYear +" was the year of the Snake");
      break;
      
      case 10:
      System.out.print ("\n" +inputYear +" was the year of the Horse");
      break;      
      
      case 11:
      System.out.print ("\n" +inputYear +" was the year of the Sheep");
      break;                           
     }                
   
   }
    
}