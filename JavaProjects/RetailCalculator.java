//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

//program has user input the wholesale price of an item and the markup percentage then outputs retail price

//import scanner, number format, and decimal format
import java.util.Scanner;
import java.text.NumberFormat;
import java.text.DecimalFormat;
public class RetailCalculator

{
   public static void main(String[] args)
   
   {
   
   double wholeSale, markUpPercent, retailPrice;
   
   Scanner input=new Scanner(System.in);
   
   //prompt user for item wholesale cost and markup percentage and store values as a double
   System.out.print ("Enter item's wholesale cost: $");
   wholeSale = input.nextDouble();
   
   System.out.print ("\nEnter the item's markup percentage: ");
   markUpPercent = input.nextDouble();
   
   //converts input to a standardized format...ie: if entered as .5 it will convert to 50
       while (markUpPercent < 1.00)
   
       markUpPercent = markUpPercent * 100;
       
   //setup to convert decimal and currency formats
   DecimalFormat dfmt = new DecimalFormat ("0.##");       
   NumberFormat $fmt = NumberFormat.getCurrencyInstance();
   
   //returns the items price after adding markup and calling the retCalc class
   retailPrice = retCalc (wholeSale, markUpPercent);
   System.out.println ("\nThe item's retail price (at a " +dfmt.format(markUpPercent) +"% markup is " 
   +$fmt.format(retailPrice));
   
   }
   
   public static double retCalc (double wholeSale, double markUpPercent)
     
   {
   
   //divides the markUpPercent by 100. This is why it was standardized earlier
   markUpPercent = markUpPercent/100;
   
   //returns a value that is equal to wholeSale+(wholeSale * markUpPercent)
   double markUp = wholeSale * markUpPercent;
   
   double retail = wholeSale + markUp;
   
   return retail; 
         
   }
   
}