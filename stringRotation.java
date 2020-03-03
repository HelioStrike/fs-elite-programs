import java.util.*;

/*
 * 
A Program to check if strings are rotations of each other or not

Given a string s1 and a string s2, 
write a snippet to say whether s2 is a rotation of s1?
example:
given s1 = ABCD and s2 = CDAB, return "YES", 
given s1 = ABCD, and s2 = ACBD , return "NO"

Sample Input:
ABACD CDABA

Sample Output:
YES

Explanation:
s2 = CDABA
after 1st rotation, s2=DABAC
after 2nd rotation, s2=ABACD
in this rotation s1==s2. strings are rotations of each other.
print YES.

 * 
 */

import java.util.Scanner;

class StringRotation 
{ 
	public static void main (String[] args) 
	{ 

		/* write your code here */
		Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int n=a.length(); int m=b.length();
        if(n!=m)
        {
            System.out.println("NO");
        }
        else
        {
            int i=0; int j=0;
            while(i<n && j<m)
            {
                if(a.charAt(i) == b.charAt(j)) {
                    i++; j++;
                } else {
                    i++;
                }
            }
            String c = b.substring(j,m)+b.substring(0,j);
            if(c.equals(a)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
	} 
} 
