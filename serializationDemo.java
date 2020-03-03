/*

Serialization and Deserialization in Java with Example

Serialization is a mechanism of converting the state of an object into a byte stream. Deserialization is the reverse process where 
the byte stream is used to recreate the actual Java object in memory. This mechanism is used to persist the object.

The byte stream created is platform independent. So, the object serialized on one platform can be deserialized on a different platform.


To make a Java object serializable we implement the java.io.Serializable interface.
The ObjectOutputStream class contains writeObject() method for serializing an Object.

public final void writeObject(Object obj) throws IOException

The ObjectInputStream class contains readObject() method for deserializing an object.

public final Object readObject() throws IOException,ClassNotFoundException

Advantages of Serialization
1. To save/persist state of an object.
2. To travel an object across a network.

Only the objects of those classes can be serialized which are implementing java.io.Serializable interface.
Serializable is a marker interface (has no data member and method). It is used to “mark” java classes so that objects of these classes 
may get certain capability. Other examples of marker interfaces are:- Cloneable and Remote.

*/
// Java code for serialization and deserialization  
// of a Java object 
import java.io.*; 
  
class Demo implements java.io.Serializable 
{ 
    public int a; 
    public String b; 
    transient int c;//Now it will not be serialized  
    
     
    // Default constructor 
    public Demo(int a, String b,int c) 
    { 
        this.a = a; 
        this.b = b; 
        this.c=c;
    } 
  
} 
  
class SerializationExample 
{ 
    public static void main(String[] args) 
    {    
        Demo object = new Demo(1, "Kmit Elite Finishing School",22); 
        String filename = "file.ser"; 
          
        // Serialization  
        try
        {    
            //Saving of object in a file 
            FileOutputStream file = new FileOutputStream(filename); 
            ObjectOutputStream out = new ObjectOutputStream(file); 
              
            // Method for serialization of object 
            out.writeObject(object); 
              
            out.close(); 
            file.close(); 
              
            System.out.println("Object has been serialized"); 
  
        } 
          
        catch(IOException ex) 
        { 
            System.out.println("IOException is caught"); 
        } 
  
  
        Demo object1 = null; 
  
        // Deserialization 
        try
        {    
            // Reading the object from a file 
            FileInputStream file = new FileInputStream(filename); 
            ObjectInputStream in = new ObjectInputStream(file); 
              
            // Method for deserialization of object 
            object1 = (Demo)in.readObject(); 
              
            in.close(); 
            file.close(); 
              
            System.out.println("Object has been deserialized "); 
            System.out.println("a = " + object1.a); 
            System.out.println("b = " + object1.b); 
            System.out.println("c = " + object1.c); 
        } 
          
        catch(IOException ex) 
        { 
            System.out.println("IOException is caught"); 
        } 
          
        catch(ClassNotFoundException ex) 
        { 
            System.out.println("ClassNotFoundException is caught"); 
        } 
  
    } 
} 
