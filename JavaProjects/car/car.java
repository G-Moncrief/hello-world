//*****************************************************************************************************
//I pledge my Honor that I have not cheated, and will not cheat, on this assignment. Garrett Moncrief.
//*****************************************************************************************************

public class Car {

   // Declare variables
   private String make;
   private String model;
   private int year;

   //Constructor without values
   public Car() {
       super();
       this.make = "-";
       this.model = "-";
       this.year = 0;
   }

   //constructor
   public Car(String make, String model, int year) {
       super();
       this.make = make;
       this.model = model;
       this.year = year;
   }

   //Get/Set Make
   public String getMake() {return make;}
   public void setMake(String make) {this.make = make;}

   //Get/Set Model
   public String getModel() {return model;}
   public void setModel(String model) {this.model = model;}

   //Get/Set Year
   public int getYear() {return year;}
   public void setYear(int year) {this.year = year;}

   //display results
   public String display() {
       return year + " " + make + " " + model;
   }

}
