/*
 * 
 Given a string s, find the longest palindromic substring in s. 
 You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.


Example 2:

Input: "cbbd"
Output: "bb"

Note:   if there are more than one longest pallindromes 
        print the first one.
*/

import java.util.*;

public class Solution
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next(); int n=s.length();
        int ans1 = 1,maxi1=0;
        int[] d1 = new int[n];
        for(int i=0,l=0,r=-1;i<n;i++) 
        {
            int k=(i>r)?1:Math.min(d1[l+r-i],r-i+1);
            while(i-k>=0 && i+k<n && s.charAt(i-k)==s.charAt(i+k)) k++;
            if(ans1<k)
            {
                ans1 = k;
                maxi1 = i;
            }
            d1[i]=k--;
            if(i+k>r)
            {
                l=i-k;
                r=i+k;
            }
        }
        int ans2 = 0,maxi2=0;
        int[] d2 = new int[n];
        for(int i=0,l=0,r=-1;i<n;i++) 
        {
            int k=(i>r)?0:Math.min(d2[l+r-i+1],r-i+1);
            while(i-k-1>=0 && i+k<n && s.charAt(i-k-1)==s.charAt(i+k)) k++;
            d2[i]=k--;
            if(ans2<k)
            {
                ans2 = k;
                maxi2 = i;
            }
            if(i+k>r)
            {
                l=i-k-1;
                r=i+k;
            }
        }
        if(2*ans1-1>=2*ans2)
        {
            int ans=1,maxi=0;
            for(int i=0;i<n;i++)
            {
                if(ans<d1[i])
                {
                    ans=d1[i];
                    maxi=i;
                }
            }
            for(int i=maxi-ans+1;i<maxi+ans;i++) System.out.print(s.charAt(i));
        }
        else
        {
            int ans=0,maxi=0;
            for(int i=0;i<n;i++)
            {
                if(ans<d2[i])
                {
                    ans=d2[i];
                    maxi=i;
                }
            }
            for(int i=maxi-ans;i<maxi+ans;i++) System.out.print(s.charAt(i));
        }
        System.out.println();
    }
}