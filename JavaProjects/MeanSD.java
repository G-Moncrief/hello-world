
import java.util.Scanner;

public class MeanSD

{ 
   //main class -- Allows user to input the 10 integers used for calculation 
   //and uses these numbers to call meanClass and stdDev class
   public static void main (String[] args){
   Scanner input = new Scanner(System.in);
   System.out.println ("Enter 10 integers:\n");
   double [] myList = new double[10];
   for (int i = 0; i < myList.length; i++)
   myList[i] = input.nextDouble();
   System.out.println("The average is " + meanCalc(myList));  
   System.out.println("The standard deviation is " + stdDev(myList));
   }
   
   //meanCalc class -- finds mean by summing the input numbers and then 
   //dividing by however many numbers were input
   public static double meanCalc (double [] list){
   double sum=0;
   for (int i = 0; i < list.length;i++)
   sum += list [i];  
   return sum / list.length;
   }
   
   //stdDev class -- finds standard deviation by taking the 
   //root of [(list-mean)^2  / length of numbers input -1]
   public static double stdDev (double [] list){ 
   double sum=0, ave=0,sd=0,stdDevCalc=0;
   for (int i = 0; i < list.length;i++){
   sum += list [i];
   ave = sum / list.length; 
      
   }
   for (int j=0; j<list.length;j++){
   sd = sd +Math.pow(list [j] - ave, 2);}
   stdDevCalc=Math.sqrt(sd/(list.length-1));
   return stdDevCalc;
   }
   
}
