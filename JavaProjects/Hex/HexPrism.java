import java.text.DecimalFormat;
public class HexPrism {

   // Declare variables
   private double base,height;
   
   //Constructor without values
   public HexPrism() {
       super();
       this.base = 0.0;
       this.height = 0.0;
   }

   //Get/Set Base
   public double getBase() {return base;}
   public void setBase(double base) {this.base = base;}

   //Get/Set Height
   public double getHeight() {return height;}
   public void setHeight(double height) {this.height = height;}
   
   //calculate and display results for area and vol. Area is calc by 6ah+3*a^2*sqrt3
   //and vol is calc by a^2*h*(3sqrt3)/2 where a=base area and h=height....also introduce
   //decimal format to return response to 3 dec places
   public String toString() {
   DecimalFormat dfmt = new DecimalFormat ("0.###");
      return "\nGiven a hexagonal prism with a base edge of " +base +" units and height of " +height +" units:"
      +"\nThe area is: " +dfmt.format((6*base*height+3*base*base*Math.sqrt(3)))+ " units squared."
      +"\nThe volume is: " +dfmt.format((((3*Math.sqrt(3))/2)*base*base*height))+" units cubed.";
      }

}
