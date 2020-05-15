/*
 * 

Given a string and number of rows 'n'. 
Print the string formed by concatenating n rows when input string is 
written in row-wise Zig-Zag fashion.

Sample Input:
ABCDEFGHIJKLM
3
Sample Output: 
AEIMBDFHJLCGK

Explanation: Let us write input string in Zig-Zag fashion
             in 3 rows.
A       E       I       M
  B   D   F   H   J   L
    C       G       K
Now concatenate the two rows and ignore spaces 
in every row. We get "AEIMBDFHJLCGK"


 * 
 */

import java.util.*;

class ZigzagStringConcat {

	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int n = sc.nextInt();
		int len = s.length();
		
		/* write your code here */
        String out = "";
		if(n==1 || n >= len) out = s;
		else
		{
            for(int i=0;i<n;i++)
            {
                boolean b = false;
                int j = i;
                while(j<len)
                {
                    out += s.charAt(j);
                    if(i==0 || i==n-1) j += 2*(n-1);
                    else if(b) j += 2*i;
                    else j += 2*(n-i-1);
                    b = !b;
                }
            }
		}
        System.out.println(out);
	}
}