//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

public class Shape {

   // Declare variables
   private String name;
   private int sides;

   //Constructor without values
   public Shape() {
       super();
       this.name = "-";
       this.sides = 0;
   }

   //constructor
   public Shape (String name, int sides) {
       super();
       this.name = name;
       this.sides = sides;
   }

   //Get/Set Name
   public String getName() {return name;}
   public void setName(String name) {this.name = name;}

   //Get/Set Sides
   public int getSides() {return sides;}
   public void setSides(int sides) {this.sides = sides;}

   //display results
   public String toString() {
      return "Shape: " +name + "\nNo. of sides:" +sides +"\n";
      }
      
  //public static method for the number of shapes     
  public int numShapes() {
      return 3;
      }

}
