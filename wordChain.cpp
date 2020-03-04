/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2,
if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  
For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, 
where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain formed using the given list of words.

 

Example 1:

Input: a b ba bca bda bdca
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

#include <bits/stdc++.h>
#define N 1010
using namespace std;

int n,ans,dp[N];
string x;
vector<string> v;

bool ispre(string a,string b)
{
    int i=0,j=b.length()-1;
    if(a.length()!=j) return false;
    while(a[j-1]==b[j]) j--;
    while(i<j && a[i]==b[i]) i++;
    return (i==j);
}

bool cmp(string s1,string s2) { return s1.length()<s2.length(); }

int main()
{
    while(cin>>x) v.push_back(x),n++;
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(ispre(v[j],v[i])) dp[i]=max(dp[i],dp[j]+1);
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    cout<<ans+1<<'\n';
}