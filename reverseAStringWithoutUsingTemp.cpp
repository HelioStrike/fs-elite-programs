/*
Program to reverse the string without using 
any temporary variable and String methods.

Sample Input : 
This is Elite Finishing School

Sample Output : 
loohcS gnihsiniF etilE si sihT
*/

//Swap 2 variables without using temp trick
//Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s=""; char c;
    while((c=getchar())!='\n') s+=c;
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        s[n-i-1]+=s[i];
        s[i]=s[n-i-1]-s[i];
        s[n-i-1]-=s[i];
    }
    cout<<s<<'\n';
}