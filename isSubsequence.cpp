/*
 * 
Given two strings A and B, check if A is subsequence of B.

B is a very long string, and A is a short string 

A subsequence of a string is a new string which is formed from the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "def" is a subsequence of "adheazgbf" while "zab" is not).

Example 1:

input:
def
adheazgbf

output:
true

Example 2:

input:
zab
adheazgbf

output:
false
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; cin>>s>>t;
    int cur=0;
    for(int i=0;i<t.length() && cur<s.length();i++) if(t[i]==s[cur]) cur++;
    cout<<(cur==s.length()?"true":"false")<<'\n';
}