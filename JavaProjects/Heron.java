//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;
import java.text.DecimalFormat; 

//This program will ask for the user to input the three sides of a triangle and will then compute and display the area

public class Heron
{
   public static void main(String[] args)
   {
   
   // declare variables 
   
   double sideA, sideB, sideC, sSum, areaCalc, areaFinal;
   
   //set up input object
   
   Scanner input = new Scanner(System.in);
   
   //prompt the user to input the three sides of a triangle
   
   System.out.println ("This program will compute the sides of a triangle to give you the area based off Heron's formula.\n");
   
   System.out.print ("Enter the length of the first side of the triangle: ");
   sideA = input.nextDouble();
   
   System.out.print ("Enter the length of second side of the triangle: ");
   sideB = input.nextDouble();
   
   System.out.print ("Enter the length of third side of the triangle: ");
   sideC = input.nextDouble();
   
   //calculate the total by first dividing the sum of the three sides by two, then multiplying that sum by (sum-a)(sum-b)(sum-c)
   //finally we take the sqrt of that sum in order to get Heron's formula
   
   sSum = (sideA + sideB + sideC) / 2.0;
   
   areaCalc = sSum * (sSum-sideA) * (sSum-sideB) * (sSum-sideC);
   
   areaFinal = (Math.sqrt(areaCalc));
   
   //output result to three decimal places
   
   DecimalFormat fmt = new DecimalFormat ("0.###");
   System.out.print ("The area of the triangle is " + fmt.format(areaFinal));
   
   
   }
    
}