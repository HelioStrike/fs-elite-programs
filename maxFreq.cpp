/*
Given an array of integers, find the most occurring element of the array and 
return any one of its indexes randomly with equal probability.

Examples:

Input: 
-1 4 9 7 7 2 7 3 0 9 6 5 7 8 9

Output:  
Element with maximum frequency present at index 6
OR
Element with maximum frequency present at Index 3
OR
Element with maximum frequency present at index 4
OR
Element with maximum frequency present at index 12

All outputs above have equal probability.
*/

#include <bits/stdc++.h>
using namespace std;

int n,x,maxm,maxi;
map<int,int> cnts,pos;

int main()
{
    while(cin>>x) cnts[x]++,pos[x]=n,n++;
    for(auto p: cnts)
    {
        if(p.second>maxm)
        {
            maxm=p.second;
            maxi=p.first;
        }
    }
    for(auto p: pos)
    {
        if(p.first==maxi)
        {
            cout<<"Element with maximum frequency present at index "<<p.second<<'\n';
            break;
        }
    }
    return 0;
}