import java.util.Scanner;
public class pentagonal

{
	public static void main(String[] args)
	
	{
		int startVal, endVal, printResult;
		Scanner input = new Scanner(System.in);
		
		System.out.print ("Enter a starting value greater than 0: ");
		startVal = input.nextInt();
		
		while (startVal <= 0)
		{
			startVal = 1;
			System.out.println ("\nYour previous entry is invalid, try again.");
			System.out.print ("Enter a starting value greater than 0: ");
			startVal = input.nextInt();
		}
		
		System.out.print ("\nEnter an ending value greater than the starting value: ");
		endVal = input.nextInt();
		
		while (endVal <= startVal)
		{
			endVal = 1;
			System.out.println ("\nYour previous entry is invalid, try again.");
			System.out.print ("Enter an ending value greater than your starting value: ");
			endVal = input.nextInt();
		}
		
		System.out.println ("\nNumber     Pentagonal Number" +"\n-----------------------------------");
		
		while (startVal <= endVal)
		{
			printResult = getPentagonalNumber (startVal);
			System.out.println ("  " +startVal +"             " +printResult);
			startVal++;
		}
	}
	
	public static int getPentagonalNumber (int startVal)
	{
		int result = (3*(startVal * startVal) - startVal)/2;
		startVal++;
		return result;
	}
}
		