/*
Given an array of integers and an integer k, 
you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
    Input=  1 1 1
    	    2
    Output= 2
    Explanation: Continuous Sets [1,1] ,[1,1] 
Example 2:
    Input=  1 2 3 4
    	    5
    Output= 1
    Explanation: Continuous Sets [2,3] only, [1,4] is not a continuous set. 
*/

#include <bits/stdc++.h>
#define N 100
using namespace std;

int x,cnt,ans,sum,a[N];
map<int,int> m;

int main()
{
    while(cin>>x)
    {
        a[cnt]=x;
        cnt++;
    }
    cnt--;
    
    sum=0; m[0]=1;
    for(int i=0;i<cnt;i++)
    {
        sum+=a[i];
        m[sum]++;
        ans+=m[sum-x];
    }
    cout<<ans<<'\n';
    
    return 0;
}