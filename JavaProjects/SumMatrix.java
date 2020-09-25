
import java.util.Scanner;

public class SumMatrix

{

   public static void main (String[] args){
   Scanner input=new Scanner (System.in);
   double [][] array1=new double [3][3]; 
   double [][] array2=new double [3][3]; 
   double [][] arraySum=new double [3][3];
   
   //Prompts user to input numbers for matrix one and stores them via nested for loops
   System.out.println ("Enter nine numbers for matrix one:\n");
   for (int row=0;row<3;row++)
      for (int col=0;col<3;col++)
      array1[row][col]=input.nextDouble();
   
   //Prompts user to input numbers for matrix two and stores them via nested for loops
   System.out.println ("Enter nine numbers for matrix two:\n");
   for (int row=0;row<3;row++)
      for (int col=0;col<3;col++)
      array2[row][col]=input.nextDouble();
   
   //prints matrix one values
   System.out.println("The addition of the matrices are:\n");
   for(int row=0;row<3;row++){
      for(int col=0;col<3;col++){
      System.out.print(array1[row][col]+"\t");
      }
   System.out.println();
   }
   
   //prints matrix two
   System.out.println("\n\t\t +\n");
   for(int row=0;row<3;row++){
      for(int col=0;col<3;col++){
      System.out.print(array2[row][col]+"\t");
      }
   System.out.println();
   }   
         
   //calls addMatrix method to print the sum of matrices 1 and 2
   System.out.println("\n\t\t =\n");
   arraySum=addMatrix(array1, array2);
   for(int row=0;row<3;row++){
      for(int col=0;col<3;col++){
      System.out.print(arraySum[row][col]+"\t");
      }
   System.out.println();
   }
   
   }

   //Method that finds the sum of numbers entered in matrices 1 and 2 and stores via nested for loops
   public static double[][] addMatrix(double[][] array1, double[][] array2){
   double[][]  arrayFinal= new double[3][3];
   for(int row=0; row< 3; row++)
      for(int col=0; col<3; col++)
      arrayFinal[row][col] = array1[row][col] + array2[row][col];
   return arrayFinal;
   }

}

