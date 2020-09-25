import java.util.Scanner;

//This program has the user input a positive integer and then outputs the reverse of integer
public class Reverse
{
   public static void main(String[] args)
   
   {
   //initialize variables
   int number=0, lastDigit=0, reverse=0, revNumOut;

   Scanner scan = new Scanner(System.in);

   //have user input positive integer
   System.out.print("Enter a positive integer: ");

   number = scan.nextInt();
   
   //call method included in assignment
   revNumOut=reversedNumber (number, lastDigit, reverse);
   System.out.print ("That number reversed is "+revNumOut);
   }
   
   //imports user input variables and runs program from assignmnent
   public static int reversedNumber (int number, int lastDigit, int reverse)
   {
   do 
      {
         lastDigit = number % 10;

         reverse = (reverse * 10) + lastDigit;

         number = number / 10;
      }
      while (number > 0);
      
      return reverse;
   }
}
