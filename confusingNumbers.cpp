/*
We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.
(Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.

 
 
 
Input: 20
Output: 6
Explanation: 
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.
*/

#include <bits/stdc++.h>
using namespace std;

int n,ans;
int con[] = {0,1,6,8,9};
int k=5;
map<int,int> m;

int rev(int c) {
    string s="";
    while(c>0)
    {
        s+=('0'+(c%10));
        c/=10;
    }
    for(int i=0;i<s.length();i++) s[i]=('0'+m[s[i]-'0']);
    int ret=0;
    for(int i=0;i<s.length();i++)
    {
        ret*=10;
        ret+=s[i]-'0';
    }
    return ret;
}

void dfs(int c)
{
    if(c>n) return;
    if(c!=rev(c)) ans++;
    for(int i=0;i<k;i++) dfs(c*10+con[i]);    
}

int main()
{
    m[0]=0,m[1]=1,m[6]=9,m[8]=8,m[9]=6;

    cin>>n;
    for(int i=1;i<k;i++)
    {
        if(con[i]<=n)
        {
            dfs(con[i]);
        }
    }
    cout<<ans<<'\n';
}