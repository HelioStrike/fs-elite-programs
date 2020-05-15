/*
 * 
 Given a bitonic sequence of n distinct elements, 
 write a program to find a given element x in the bitonic sequence in O(log n) time. 
 A Bitonic Sequence is a sequence of numbers which is first strictly increasing then 
 after a point strictly decreasing.

Examples:

Input : 
-3 9 8 20 17 5 1
20
Output :3

Input :
5 6 7 8 9 10 1 2 3
30
Output : -1 



 */



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BitonicArray {


	    public static void main(String args[])  throws IOException {

		    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str = br.readLine();
			String[] numbers = str.split(" ");
			int[] arr = Arrays.asList(numbers).stream().mapToInt(Integer::parseInt).toArray(); 
	        int key; int n=arr.length;
	        key=Integer.parseInt(br.readLine());
	       
	        int l,h,m1,m2;
	        l=0; h=n-1;
	        for(int i=0;i<20;i++)
	        {
	            m1=(h-l)/3+l;
	            m2=(2*(h-l))/3+l;
	            if(arr[m1]<arr[m2]) l=m1;
	            else h=m2;
	        }
	        
	        int n1=Arrays.binarySearch(arr,0,m1,key);
	        int n2=Arrays.binarySearch(arr,m1,n-1,key,Collections.reverseOrder());
	        if(arr[n1]==key) System.out.println(n1);
	        else if(arr[n2]==key) System.out.println(n2);
	        else System.out.println(-1);
	    } 
}