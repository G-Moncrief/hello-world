//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;
import java.util.Random;

//this program will ask for a user's first and last name in order to generate a six character alphanumeric username

public class Usernames
{
   public static void main(String[] args)
   {
   
   //declare variables
   
   String firstName;
   String lastName;
   
   //setup input object
   Scanner input = new Scanner(System.in);
   
   //prompt user for first and last name.  Note, for last name string "XXX" is included in case user has a name that is less 
   //than three letters long
   
   
   System.out.print ("Enter first name: ");
   firstName = input.next();
   
   
   System.out.print ("Enter last name: ");
   lastName = input.next() + ("XXX");
   
   //generate random number
   
   int ranNum = 10 + (int)(Math.random()*89);
   
   //generate a username that consists of the first letter of the first name, first three of last name, and two digit random number
   
   String username = firstName.substring(0,1) + lastName.substring(0,3)+ ranNum;
   
   //print out result to user
   
   System.out.println("Your username is: " + username);
   


   }
    
}