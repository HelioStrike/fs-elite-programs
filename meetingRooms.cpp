/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
(si < ei), find the minimum number of conference rooms required.

IO Format:
Input Format:   An integer N, size of an array of meeting time intervals
	            N lines of Input, consisting of start and end times. where start<end.
Output Format:  An integer, indicates the minimum number of conference rooms required

Example 1:

    Input:  3
            0 30
            5 10 
            15 20
    Output: 2
Example 2:

    Input:  2
            7 10
            2 4
    Output: 1

Example 2:

    Input:  3
            5 10
            10 20
            15 25
    Output: 2
    Note: if both 'end' and 'start' time of two events are same, they can allocate same room 
*/

//Time Complexity - O(n)

#include <bits/stdc++.h>
#define M 1000
using namespace std;

int tme[M];

int main()
{
    int n,x,y; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        tme[x]++;
        tme[y]--;
    }
    int cur=0,ans=0;
    for(int i=0;i<M;i++)
    {
        cur+=tme[i];
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}