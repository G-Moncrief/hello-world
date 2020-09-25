//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************
import java.util.Scanner;

public class CarTest {

   public static void main(String[] args) {
   
    //Declare local variables
       int year;
       String make,model;
       Scanner input=new Scanner(System.in);
      
    //Create the car class obejcts
       Car car1=new Car("Ford","Taurus",2015);
       Car car2=new Car("Honda","Accord",2007);
       Car car3=new Car();
     
   //Display car info
   System.out.println("SMITH AUTO ACCOUNT\n======================");
      System.out.println("*\t" +car1.display());
      System.out.println("*\t" +car2.display());
      System.out.println("*\t" +car3.display());
      System.out.println ("======================");
      
   //Enter car 3 info
      System.out.println("\nThird vehicle information missing, please enter make, model, and year:");
         System.out.print("Make: ");
         make=input.next();
         car3.setMake(make);
         
         System.out.print("Model: ");
         model=input.next();
         car3.setModel(model);
         
         System.out.print("Year: ");
         year=input.nextInt();
         car3.setYear(year);
      
  //Update Ford model
   System.out.println("\nMr. Smith traded the Taurus for another Ford from the same year.");
      System.out.print("Enter the new Ford model:");
      model=input.next();
      car1.setModel(model);

   //Update Accord Year
   System.out.println("\nMr. Smith sold the 2007 Accord to buy a more current version.");
      System.out.print("Enter the new year for the Accord:");
      year=input.nextInt();
      car2.setYear(year);

   //Displat updated acct info
   System.out.println("\nSMITH AUTO ACCOUNT\n*UPDATED*\n======================");
      System.out.println(car1.display());
      System.out.println(car2.display());
      System.out.println(car3.display());
      System.out.println ("======================");
  
   }

}