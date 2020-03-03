/*
Given an integer 'd' between 0 and 9 , and two positive integers low and high as lower and upper 
bounds, respectively. Return the number of times that 'd' occur as a digit in all integers 
between low and high , including the bounds low and high .

I/O Format:
Input Format:   an integer, indicates value of 'd'
                an integer, indicates value of 'lower bound'
                an integer, indicates value of 'higher bound'
Output Format:  an integer, indicates number of times that 'd' occur as a digit 
                in all integers between low and high
Example 1:
    Input:  1
            1
            13
    Output: 6

Explanation:
The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1 occurs twice in the number 11.

Example 2:
    Input:  3   
            100
            250
    Output: 35

Explanation:
The digit d=3 occurs 35 times in 103,113,123,130,131,...,238,239,243.

Note:
    0 <= N <= 9
    1 <= low <= high <= 2×10^8
*/

#include <bits/stdc++.h>
using namespace std;

int countInPos(int n,int pos,int d)
{
    int po10=pow(10,pos);
    int npo10=po10*10;
    int right=n%po10;
    int rd=n-n%npo10;
    int ru=npo10+rd;
    int digit=(n/po10)%10;
    if(digit<d) return rd/10;
    else if(digit==d) return rd/10+right+1;
    return ru/10;
}

int getDigitCount(int x,int d)
{
    int c=x,len=0,ans=0;
    while(c) c/=10,len++;
    for(int k=0;k<len;k++) ans+=countInPos(x,k,d);
    return ans;
}

int main()
{
    int d,l,h; cin>>d>>l>>h;
    cout<<getDigitCount(h,d)-getDigitCount(l-1,d)<<'\n';
}