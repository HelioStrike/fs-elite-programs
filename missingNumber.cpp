/*
You are given a list of n-1 integers and these integers are in the range of 1 to n.
There are no duplicates in the list. One of the integers is missing in the list.
Write an efficient code to find the missing integer.

Example :

Input:1 2 4 6 3 7 8
Output: 5

Time Complexity :O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int n,x,sum;

int main()
{
    while(cin>>x) n++,sum+=x;
    cout<<((n+1)*(n+2)/2)-sum<<'\n';
}