/*
Govind is working with an array of integers, 
He is trying to find a trio whose sum is equal to the given value K form the array.

If there is such a trio present in array, 
then print the trio else return -1. 
 
 
Example-1:
 
    Input=  12 3 4 1 6 9
            24
    Output= [1, 9, 12]

Example-2:
    Input=  17 5 21 12 3 4 11 26 9
            57
    Output= -1

Note : Output should be in the ascending order
There will be only one trio possible or none.
 
 
*/

#include <bits/stdc++.h>
using namespace std;

int n,x,k;
vector<int> v;

int main()
{
    while(cin>>x) v.push_back(x);
    k=*(--v.end()); v.pop_back(); n=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        map<int,int> m;
        for(int j=i+1;j<n;j++)
        {
            if(m[k-v[i]-v[j]]) 
            {
                cout<<v[i]<<' '<<k-v[i]-v[j]<<' '<<v[j]<<'\n';
                return 0;
            }
            m[v[j]]=j;
        }
    }
    cout<<-1<<'\n';
    return 0;
}