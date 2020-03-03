/*
 * 
 Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Input: ())
Output: 1
Example 2:

Input: (((
Output: 3
Example 3:


Note:

S.length <= 1000
S only consists of '(' and ')' characters.


 
 */



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class minAddParentheses {
	public static int minAddToMakeValid(String S) {
      // write your code here
    }
	
	  public static void main(String args[])  throws IOException {

		    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String S = br.readLine();

			System.out.println(minAddToMakeValid(S));
	  
	    } 
	
	
}