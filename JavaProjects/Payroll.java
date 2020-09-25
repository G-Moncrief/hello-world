//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

import java.util.Scanner;
import java.text.NumberFormat; 

//This program is designed to give a simple payroll breakdown for an employee at regular pay (40 hrs or less) by calculating the
//deductions from federal and state tax. It then provides a line by line breakdown of gross pay, tax deductions, and net pay.

public class Payroll
{
   public static void main(String[] args)
   {

   //define variables 
   
   double  hoursWork, payRate, grossPay, fedTaxDed, stateTaxDed, totDed, netPay,fedTax, stateTax;

   
   String employeeName;
   
   //setup input object
   Scanner input = new Scanner(System.in);
   
   //prompt user for employee name, number of hours worked, pay rate, and federal and 
   //state tax (entered in decimal format ie: 20% = 0.20
   
   System.out.println ("Employee standard pay calculator \n");
   
   
   System.out.print ("Enter the employee's name: ");
   employeeName = input.nextLine();
   
   System.out.print ("Enter the number of hours worked: ");
   hoursWork = input.nextDouble();
   
   System.out.print ("Enter the hourly pay rate: ");
   payRate = input.nextDouble();
   
   System.out.print ("Enter the federal tax withholding rate (in decimal format): ");
   fedTax = input.nextDouble();
   
   System.out.print ("Enter the state tax withholding rate (in decimal format): ");
   stateTax = input.nextDouble();
   
   //calculate gross pay (hours*pay rate) federal tax deduction (gross pay * fed tax rate) 
   //state tax deductions (gross pay * state tax rate) total deductions (state + federal tax rates)
   //and net pay (gross pay - total deductions
   
   grossPay = (hoursWork * payRate);
   
   fedTaxDed = (grossPay * fedTax);
   
   stateTaxDed = (grossPay * stateTax);
   
   totDed = (fedTaxDed + stateTaxDed);
   
   netPay = (grossPay - totDed);
   
   //print out results to user. Specifically uses NumberFormat.getCurrencyInstance and 
   //NumberFormat.getCurrencyInstance to properly format output
   
   System.out.println ("\n=============\n   RESULTS\n=============");
   
   
   System.out.println ("\nEmployee Name: " + employeeName);
   
   System.out.println ("Hours Worked: " +hoursWork);
   
   System.out.println ("Pay Rate: $" +payRate);
   
   NumberFormat fmt = NumberFormat.getCurrencyInstance();
   System.out.println ("\nGross Pay: " + fmt.format(grossPay));
   
   System.out.println ("Deductions:");
   
   NumberFormat pct1 = NumberFormat.getPercentInstance();
   NumberFormat fmt1 = NumberFormat.getCurrencyInstance();
   System.out.println ("\tFederal Tax @" + pct1.format(fedTax) + ": " + fmt1.format(fedTaxDed));
      
   NumberFormat pct2 = NumberFormat.getPercentInstance();
   NumberFormat fmt2 = NumberFormat.getCurrencyInstance();   
   System.out.println ("\tState Tax @" + pct2.format(stateTax) + ": " + fmt2.format(stateTaxDed));
   
   NumberFormat fmt3 = NumberFormat.getCurrencyInstance();
   System.out.println ("\tTotal deduction: " + fmt3.format(totDed));
   
   NumberFormat fmt4 = NumberFormat.getCurrencyInstance();
   System.out.println ("\tNet Pay: " + fmt4.format(netPay));

  
    }
    
}