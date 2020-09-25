import java.util.Scanner;

public class HexDriver {

   public static void main(String[] args) {
   
    //Declare local variables
       double base, height;
       Scanner input=new Scanner(System.in);
      
    //Create the shape class obejcts
       HexPrism hex=new HexPrism();
   
   //Enter Base/Height info
      System.out.print("\nEnter the base edge of a Hexagonal Prism: ");
      base=input.nextDouble();
      hex.setBase(base);
         
      System.out.print("Enter the height of a Hexagonal Prism: ");
      height=input.nextDouble();
      hex.setHeight(height);
        
   //Display the area and vol for numbers entered
      System.out.println(hex.toString());
  
   }

}
