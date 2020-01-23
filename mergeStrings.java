
/*
 * 
You are merging data from two sources connected to a network access point to create a new data packet. 

You must merge strings a and b, and the return a single merged string. 
A merge operation on two strings is described as follows.

Append alternating characters from a and b, respectively, to some new string mergedString.
Once all of the characters in one of the strings have been merged, 
append the remaining characters in the other string to mergedString.

As an example, assume you have two strings to merge : 'abc' and 'stuvwx'. 
Alternate between the first and second strings as long as you can :

'a' + 's'+'b'+'t'+'c' +'u'. At this point you have traversed the first string and have generated 'asbtcu'. 
The remainder of the second string ,'vwx' is now added to the end of the string, creating 'asbtcuvwx'.

Sample Input:
kmit
ngit

Sample Output:
knmgiitt


 * 
 */

import java.util.Scanner;

public class MergeStrings {

	public static void main(String[] args)
    { 
		/* write your code here */
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine(); int x=a.length();
		String b = sc.nextLine(); int y=b.length();
		int i=0;
		int j=0;
		String s="";
		while(i<x && j<y)
		{
		    s+=a.charAt(i);
		    s+=b.charAt(j);
		    i++; j++;
		}
		while(i<x)
		{
		    s+=a.charAt(i);
		    i++;
		}
		while(j<y)
		{
		    s+=b.charAt(j);
		    j++;
		}
		System.out.println(s);
    } 
  
    


}