/*
You have some sticks with positive integer lengths.
You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y . 
You perform this action until there is one stick remaining.
Return the minimum cost of connecting all the given sticks into one stick in this way.

IO Format:
Input Format:   An integer N, indicates no.of.sticks
        	    N integers, indicates the length of sticks
Output Format:  An integer, indicates the minimum cost of connecting all the given sticks 

Example 1:
    Input: 3
    2 4 3
    Output: 14
    
    Explanation: there are 3 sticks of lengths 2, 4, 3 
    Connect 2,3 --> 5, new sticks- 5, 4
    Connect 5,4 -> 9, new sticks- 9
    Total cost --> 14 

Example 2:
    Input: 5
    6 2 8 5 9
    Output: 67
    
    Explanation: there are 3 sticks of lengths 2, 4, 3 
    Connect 2,5 --> 7, new sticks- 7, 6, 8, 9
    Connect 6,8 -> 14, new sticks- 7, 14, 9
    Connect 7,9 --> 16, new sticks- 16, 14
    Connect 16,14 -> 30, new sticks- 30
    Total cost --> 67

Constraints:
1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4
*/

//Combine 2 sticks with shortest length and add the new stick to priority queue
//Time Complexity - O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,sum=0; cin>>n;
    priority_queue<int> pq;
    for(int i=0;i<n;i++) cin>>x,pq.push(-x); 
    for(int i=1;i<n;i++)
    {
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        sum+=a+b;
        pq.push(a+b);
    }
    cout<<-sum<<'\n';
}