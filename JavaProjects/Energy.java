import java.util.Scanner;

/*
 *	This program will prompt user for a mass of water, initial, and final 
 *	temperature (in C) and output energy required in joules to heat the
 *	mass of water
 */

public class Energy
{
   public static void main(String[] args)
   {
     //declare constants
     final int waterHeatCap = 4184;
     
     //declare variables
     float mass, tempInit, tempFinal, energy;
     
     //set up input object
    Scanner input = new Scanner(System.in);
    
    //prompt user for mass of water and initial/final temperatures
    System.out.print ("Enter the mass of water to be calculated (in kilograms): ");
    mass = input.nextFloat();
    System.out.print ("Enter the initial temperature (in degrees Celsius): ");
    tempInit = input.nextFloat();
    System.out.print ("Enter the temperature for water to be heated to (in degrees Celsius): ");
    tempFinal = input.nextFloat();
    
    //calculate energy so that it equals the mass times the difference in temperatures times the specific heat capacity of water
    energy = mass * (tempFinal - tempInit) * waterHeatCap;
    
    //display results of above calculation
    System.out.println("It would take " + energy + " joules to heat " + mass + " kg of water from " + tempInit + " degrees Celsius to "
    + tempFinal + " degrees Celsius." ) ;
    }
}