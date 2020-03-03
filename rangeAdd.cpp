/*
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments 
each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

    Input=	5		//array size, s
    		3		//no.of.operations, n
    		1 3 2	//next 'n' triplets
    		2 4 3
    		0 2 -2
    Output= [-2,0,3,5,3]	//modified array
    Explanation:
    Initial state:
    [0,0,0,0,0]
    
    After applying operation [1,3,2]:
    [0,2,2,2,0]
    
    After applying operation [2,4,3]:
    [0,2,5,5,3]
    
    After applying operation [0,2,-2]:
    [-2,0,3,5,3]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,y,v; cin>>n>>k;
    int a[n]; memset(a,0,sizeof(a));
    for(int i=0;i<k;i++)
    {
        cin>>x>>y>>v;
        a[x]+=v; a[y+1]-=v;
    }
    cout<<a[0]<<' ';
    for(int i=1;i<n;i++) a[i]+=a[i-1],cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}