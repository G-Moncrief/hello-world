//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;
import java.text.DecimalFormat; 

//This program will use Cramer's rule to solve a 2 x 2 system of linear equation by using 
//ax+by=e   and    cx+dy=f

public class Cramer

{
   public static void main(String[] args)
   
  
   
   {
   
    //declare variables
     
     float varA, varB, varC, varD, varE, varF, solX, solY, checkVar;
     
    //set up input object
    Scanner input = new Scanner(System.in);
     
    //ask user to input A-F values
    
    System.out.print ("Enter variable A: ");
    varA = input.nextFloat();
    
    System.out.print ("Enter variable B: ");
    varB = input.nextFloat();
    
    System.out.print ("Enter variable C: ");
    varC = input.nextFloat();
    
    System.out.print ("Enter variable D: ");
    varD = input.nextFloat();
    
    System.out.print ("Enter variable E: ");
    varE = input.nextFloat();
    
    System.out.print ("Enter variable F: ");
    varF = input.nextFloat();
    
    //run check to see if ad-bc=0....if so print out the equations and that there is no solution
    
    checkVar = varA*varD - varB*varC;
    
    if (checkVar==0)
      
      System.out.print ("This program will solve an equation of the form:\nax + by = e \ncx + dy = f"
      + "\n\nBased on your input, the equations are: \n\n" +varA + "x + " +varB + "y = " + varE + "\n"
      + varC + "x + " + varD + "y = " +varF + "\n\nNo solution for these equations.");
    
    //otherwise compute x and y by the formula X=(ed-bf)/(ad-bc) and Y=(af-ec)/(ad-bc)...display equations
    //and the values of X and Y to user
    
    else
      {
      solX = (varE*varD-varB*varF)/(varA*varD-varB*varC);
      solY = (varA*varF-varE*varC)/(varA*varD-varB*varC);
      DecimalFormat fmt = new DecimalFormat ("0.###");
      System.out.print ("This program will solve an equation of the form:\nax + by = e \ncx + dy = f"
      +"\n\nBased on your input, the equations are: \n\n" +varA + "x + " +varB + "y = " + varE + "\n"
      + varC + "x + " + varD + "y = " + varF + "\n\nx is " + fmt.format(solX) + " and y is " + fmt.format(solY));
      }
      

   }
    
}
