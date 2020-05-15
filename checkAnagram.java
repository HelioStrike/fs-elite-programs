/*
 * 
 Find if 2 strings are anagrams, is it possible to find it in o(n) time and O(1) space.
 
input:god
dog
 
 output:
 true
 
 
 input:kmit
 ngir
 
 output:
 false
 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class IsAnagram {

	private static boolean isAnagramWithOneArray(String strFirst, String strSecond) {
	    // write your code
	}
	
	   public static void main(String args[])  throws IOException {

		    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String strFirst = br.readLine();
			String strSecond = br.readLine();

			System.out.println(isAnagramWithOneArray(strFirst,strSecond));
	  
	    } 
	
}