/*Suppose we have a class:

public class PrintInOrder {
  public void first() { print("A"); }
  public void second() { print("B"); }
  public void third() { print("C"); }
}
The same instance of PrintInOrder will be passed to three different threads. Thread A will call first(), 
thread B will call second(), and thread C will call third().

Design a mechanism and modify the program to ensure that second() is executed after first(), and 
third() is executed after second().

 

Example 1:

Input: [1,2,3]
Output: "ABC"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means 
thread A calls first(), thread B calls second(), and thread C calls third().
"ABC" is the correct output.
Example 2:

Input: [1,3,2]
Output: "ABC"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and 
thread C calls second(). "ABC" is the correct output.

*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.Semaphore;


import java.util.concurrent.*;
class PrintInOrder {
    
    Semaphore run2, run3;

    public PrintInOrder() {
        run2 = new Semaphore(0);
        run3 = new Semaphore(0);
    }
    
    Runnable printFirst = new Runnable() {
        public void run() {
            try {
                System.out.print("A");
            } catch(Exception e) {
                
            }
            run2.release();
        }
    };
    
    Runnable printSecond = new Runnable() {
        public void run() {
            try {
                run2.acquire();
                System.out.print("B");
            } catch(Exception e) {
                
            }
            run2.release();
            run3.release();
        }
    };
    
    Runnable printThird = new Runnable() {
        public void run() {
            try {
                run3.acquire();
                System.out.print("C");
            } catch(Exception e) {
                
            }
            run3.release();
        }
    };
    
    public static void main(String[] args) throws IOException, InterruptedException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        PrintInOrder p = new PrintInOrder();
		String str = br.readLine();
		String[] numbers = str.split(" ");
		int[] arr = Arrays.asList(numbers).stream().mapToInt(Integer::parseInt).toArray();
        Thread one = new Thread(p.printFirst);
        Thread two = new Thread(p.printSecond);
        Thread three = new Thread(p.printThird);

        for(int a:arr)
		{
        	if(a==1) 
        		one.start();
        	if(a==2)
        		two.start();
        	if(a==3)
        		three.start();
        
		}

    }
}