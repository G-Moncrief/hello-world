import java.util.Scanner;

//this program will take user input seconds and output hours/min/sec

public class SecondsConv
{
   public static void main(String[] args)
   {
     //declare constants
     final int MIN_IN_HOUR = 60;
     final int SEC_IN_MIN = 60;
     
     //declare variables
    long hours, minutes, seconds, totMin, inputSec;
    
    //set up input object
    Scanner input = new Scanner(System.in);
    
    //prompt user for number of seconds
    System.out.print ("Enter the number of seconds (in whole seconds): ");
    inputSec = input.nextLong();
    
    //calculate the number of hours, minutes,seconds. This is done by finding any seconds that are not a multiple of 60 and setting them
    //aside, find minutes not a mult of 60 and setting them aside, and then calc each mult of 60 min as an hour. This way we have an
    //output that displays hours in 60 unit multiples of 60, minutes as the remainder multiples of 60, and sec as remainders < 60
    seconds = inputSec % SEC_IN_MIN;
    totMin = inputSec / SEC_IN_MIN;
    minutes = totMin % MIN_IN_HOUR;
    hours = totMin / MIN_IN_HOUR;
    
    //display results
    System.out.println(inputSec + " seconds is  " + hours + " hours,  " + minutes + " minutes, and " 
    + seconds + " seconds." );
    
    }
    
}
   