import java.util.Scanner;

public class ShapeTest {

   public static void main(String[] args) {
   
    //Declare local variables
       int sides;
       String name;
       Scanner input=new Scanner(System.in);
      
    //Create the shape class obejcts
       Shape shape1=new Shape();
       Shape shape2=new Shape();
       Shape shape3=new Shape();
      
   //References static var
   System.out.print("Enter info on " +shape1.numShapes() +" shapes.\n"); 
   
   //Enter shape 1 info
      System.out.print("\nEnter the name of shape one: ");
      name=input.next();
      shape1.setName(name);
         
      System.out.print("Enter the number of sides for shape one: ");
      sides=input.nextInt();
      shape1.setSides(sides);
         
   //Enter shape 2 info 
      System.out.print("\nEnter the name of shape two: ");
      name=input.next();
      shape2.setName(name);
         
      System.out.print("Enter the number of sides for shape two: ");
      sides=input.nextInt();
      shape2.setSides(sides);         
      
   //Enter shape 3 info
      System.out.print("\nEnter the name of shape three: ");
      name=input.next();
      shape3.setName(name);
         
      System.out.print("Enter the number of sides for shape three: ");
      sides=input.nextInt();
      shape3.setSides(sides);      


   //Display shape info...also calls on static var
   System.out.println("Here is the info you entered for the "+shape1.numShapes()+ " shapes:\n");
      System.out.println(shape1.toString());
      System.out.println(shape2.toString());
      System.out.println(shape3.toString());
  
   }

}
