/*
Given an array nums of n integers where n > 1,  
return an array output such that output[i] is equal 
to the product of all the elements of nums except nums[i].

Example:
	Input:  1 2 3 4
	Output: 24 12 8 6
*/

#include <bits/stdc++.h>
#define N 100
using namespace std;

int n,x,a[N],l[N],r[N];

int main()
{
    while(cin>>x) a[n++]=x;
    l[0]=r[n-1]=1;
    for(int i=1;i<n;i++) l[i]=l[i-1]*a[i-1];
    for(int i=n-2;i>=0;i--) r[i]=r[i+1]*a[i+1];
    for(int i=0;i<n;i++) cout<<l[i]*r[i]<<' ';
    cout<<'\n';
    
    return 0;
}