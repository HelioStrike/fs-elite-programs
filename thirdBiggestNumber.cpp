/*
Given an array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
    Input: 3 2 1
    Output: 1
    Explanation: The third maximum is 1.

Example 2:
    Input: 1 2
    Output: 2
    Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
    Input: 2 2 3 1
    Output: 1
    Explanation: Note that the third maximum here means the third maximum distinct number.
    Both numbers with value 2 are both considered as second maximum.
    
Should not use sort() method
*/

#include <bits/stdc++.h>
using namespace std;

int x,a[3];
map<int,bool> m;

void update(int x)
{
    if(x>a[0]) { a[2]=a[1]; a[1]=a[0]; a[0]=x; }
    else if(x>a[1]) { a[2]=a[1]; a[1]=x; }
    else if(x>a[2]) { a[2]=x; }
}

int main()
{
    while(cin>>x) if(!m[x]) update(x),m[x]=1;
    cout<<((a[2]==0)?a[0]:a[2])<<'\n';
}