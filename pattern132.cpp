/*
 * 
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak 
such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers 
as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: 1 2 3 4

Output: False

Explanation: There is no  pattern in the sequence.
Example 2:
Input: 3 1 4 2

Output: True

Explanation: There is a pattern in the sequence: [1, 4, 2].
Example 3:
Input: -1 3 2 0

Output: True

Explanation: There are three patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

 */

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,x,minm=999999; cin>>n;
    stack<pair<int,int> > s;
    bool pos=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        minm=min(x,minm);
        while(!s.empty() && s.top().first<x) s.pop();
        if(!s.empty() && x<s.top().first && x>s.top().second) { pos=1; break; }
        s.push({x,minm});
    }
    cout<<pos<<'\n';

    return 0;
}
