//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************
import java.util.Scanner;
public class Prime {

    public static void main(String[] args) {
        //setup input obj and def variables
        Scanner input = new Scanner(System.in);
        int inputNum;
        boolean replayScript=false;
        //while will repeat while replayScript is false. If user states "no" to another number this val will become true and 
        //will not repeat
        while(!replayScript){
            //user input of number
            int lineNum = 0;
            System.out.print ("Enter a number greater than 2: ");
            inputNum = input.nextInt();
            //if number is not greater than 2 will prompt user for valid number
            if (inputNum<2)
                
                System.out.print ("Invalid input. Enter a number that is greater than 2: ");
            
            else
                
                System.out.println ("\nThe prime numbers from 2 - " +inputNum + " are: \n");
            //while number is less than or equal to the user input number the script will check a number if prime and then advance to next number
            //each iteration will also increase the lineNum by one
            for (int num = 2; num<=inputNum; num++){
                if (primeChk(num)){
                    System.out.print(num + " ");
                    lineNum++;
                }
                //if ten numbers have been printed on a line the lineNum value that was increasing in the script above will reset to zero and 
                //the script will start printing numbers on the next line down
                if (lineNum==10){
                    lineNum=0;
                    System.out.println("");
                }
            }
            
            //prompts user if they want to enter another number...and answer of "no" or "No" will change the replayScript value to true so 
            //that the condtion is no longer met to run the while statement
            System.out.println("\n\nDo you want to enter another number?");
            System.out.println("Enter yes or no");
            String resp = input.next();
            
            if (resp.equalsIgnoreCase("no")){
                replayScript=true;
            }
        }
    }
    //the script that checks for prime numbers. Script will check each number from 2 to the user input number -1 to see if any numbers 
    //are div without a remainder. If they are, boolean returns false, dn print number, and increases to next sequential number to check
    //...if no numbers can be found that can be divided w/o a remainder than that number is prime and boolean returns a true value and the
    //number is printed 
    public static boolean primeChk (int num){
        for(int i=2; i<num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    
}
