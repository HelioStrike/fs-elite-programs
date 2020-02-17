/*
 * 
 Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: 10 9 2 5 3 7 101 18
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?


 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,x;
    vector<int> v;
    while(cin>>x) v.push_back(x),n++;
    int cur=1,ok[n];
    ok[0]=v[0];
    for(int i=1;i<n;i++)
    {
        int pos=lower_bound(ok,ok+cur,v[i])-ok;
        if(pos==cur) cur++;
        ok[pos]=v[i];
    }
    cout<<cur<<'\n';
}