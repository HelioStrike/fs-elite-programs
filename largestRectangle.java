/*
Problem: write a program to find Maximum area for given sequence of plots.
In a layout of plots, all plots are having equal width, which is 10 meters, but these
plots varies in length For a given sequence of plots lengths, you need find what is maximum
rectangle area you can make ?

		 ----------
 		 |		  |
---------|        |	
|		 | 		  |---------
| 30*10	 | 40*10  |	25*10  |
|		 |		  |		   |---------
|		 |		  |		   |  20*10 |
-------------------------------------
 
Sample Input:
4
30 40 25 20 

Sample Output:
800

Explanation:
	 Max Area is 4*10*20 = 800 sq meters

 */

import java.util.*;

public class MaxAreaOfSeqOfPlots {
	
	
	public static void main(String args[]) {
		
		Scanner sc=new Scanner(System.in);
	    int n=sc.nextInt();
	    int arr[]=new int[n];
	    for(int i=0;i<n;i++) arr[i]=sc.nextInt();
        Stack<Integer> s=new Stack<Integer>();
        s.push(0);
        int ans=10*arr[0];
        for(int i=1;i<n;i++)
        {
            while(!s.isEmpty() && arr[s.peek()]>arr[i])
            {
                ans=Math.max(ans,10*arr[i]*(i-s.peek()+1));
                if(s.size()==1) ans=Math.max(ans,10*arr[s.peek()]*(i+1));
                s.pop();
            }
            ans=Math.max(ans,10*arr[i]);
            s.push(i);
        }
        int fin=0;
        while(!s.isEmpty())
        {
            fin=s.peek(); s.pop();
            ans=Math.max(ans,10*(n-fin)*arr[fin]);
        }
        ans=Math.max(ans,10*n*arr[fin]);
        
        System.out.println(ans);
	}
}