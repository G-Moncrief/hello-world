//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;

//This program takes user input radius and height and returns the surface area of produced cylinder
public class CylinderSA
{
   public static void main(String[] args)
   
   {
   //initialize scanner and variables
   double height, radius,areaOutput;
   
   Scanner input=new Scanner(System.in);
   //prompt user for radius and height
   System.out.print ("Enter the cylinder's radius: ");
   radius = input.nextDouble();
   
   System.out.print ("Enter the cylinder's height: ");
   height = input.nextDouble();
   
   //call on CylSA method
   areaOutput = CylSA (height, radius);
   System.out.println ("\nThe surface area of that cylinder is: "+areaOutput);
   
   
   }
   
   public static double CylSA (double height, double radius)
   
   //use input height and radius to compute area via A = 2pirh + 2pir^2
   {
   double area = 2* Math.PI*radius*height+2*Math.PI*(Math.pow(radius,2));
   
   return area;
   }
   
}