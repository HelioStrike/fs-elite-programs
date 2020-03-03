/*

Singleton design pattern is used when you want to have only one instance of a given class.

It is a creational design pattern wherein we deal with the creation of objects.

Implement the code in getInstance() of given class Singleton1 
to generate the desired output as follows. 
Sample I/O:
    input =     KmIT
    output =    String from x is KMIT                                                                                                  
                String from y is KMIT                                                                                                   
                String from z is KMIT                                                                                                   
                String from x is kmit                                                                                                   
                String from y is kmit                                                                                                   
                String from z is kmit 
*/




import java.util.Scanner;

class Singleton1
{ 
 // static variable single_instance of type Singleton 
 private static Singleton1 single_instance = null; 

 // variable of type String 
 public String s; 
 Scanner sc=new Scanner(System.in);
 // private constructor restricted to this class itself 
 private Singleton1()
 { 
     s=sc.nextLine();
 } 

 // static method to create instance of Singleton class 
 public static Singleton1 getInstance() 
 { 
    //implement this method
 } 
} 

class Singleton
{
 public static void main(String args[]) 
 { 
     // instantiating Singleton class with variable x 
     Singleton1 x = Singleton1.getInstance(); 

     // instantiating Singleton class with variable y 
     Singleton1 y = Singleton1.getInstance(); 

     // instantiating Singleton class with variable z 
     Singleton1 z = Singleton1.getInstance(); 

     // changing variable of instance x 
     x.s = (x.s).toUpperCase(); 

     System.out.println("String from x is " + x.s); 
     System.out.println("String from y is " + y.s); 
     System.out.println("String from z is " + z.s); 
     // changing variable of instance z 
     z.s = (z.s).toLowerCase(); 
     System.out.println("String from x is " + x.s); 
     System.out.println("String from y is " + y.s); 
     System.out.println("String from z is " + z.s); 
 } 
} 