/*
 * The longest Zig-Zag subsequence problem is to find length of 
 * the longest subsequence of given sequence such that all elements of 
 * this are alternating. 
 * 
 * If a sequence {x1, x2, .. xn} is alternating sequence then its element satisfy 
 * one of the following relation :
  x1 < x2 > x3 < x4 > x5 < …. xn or 
  x1 > x2 < x3 > x4 < x5 > …. xn 
  
Sample Input:
8
10 22 9 33 49 50 31 60

Sample Output: 
6

Explanation:
The subsequences {10, 22, 9, 33, 31, 60} or
{10, 22, 9, 49, 31, 60} or {10, 22, 9, 50, 31, 60}
are longest Zig-Zag of length 6.


 */

import java.io.*;
import java.util.Scanner; 

class LongestZigZag { 

//Function to return longest  Zig-Zag subsequence length 
static int longestZigZagSubseqLen(int arr[], int n) 
{ 
 // write your code here
    if(n<3) return n;
    int ans=0;
    int dp[][] = new int[n][2]; dp[0][0]=dp[0][1]=1;
    for(int i=1;i<n;i++) dp[i][0]=dp[i][1]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]) dp[i][0]=Math.max(dp[i][0],dp[j][1]+1);
            else dp[i][1]=Math.max(dp[i][1],dp[j][0]+1);
        }
    }
    for(int i=0;i<n;i++) ans=Math.max(ans,Math.max(dp[i][0],dp[i][1]));
    
    return ans;
} 

public static void main(String[] args) 
{ 
	Scanner sc = new Scanner(System.in);
	int noOfElements = sc.nextInt();
	int[] arr  = new int[noOfElements];
	for(int i=0;i<noOfElements;i++)
		arr[i]=sc.nextInt();
	
	System.out.println(longestZigZagSubseqLen(arr, noOfElements)); 
} 
} 
