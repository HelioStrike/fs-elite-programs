/*
In a school, Teacher has given a task to her students.
Teacher ask the students to find out, all the start indices othe anagrams of P in S.
Both S and P are strings consists of lowercase alphabets only. 

Print the indices in ascending order only.


Example 1:
    Input=  cbaebabacd
            abc
    Output= [0, 6]
    Explanation:
        The substring with start index = 0 is "cba", which is an anagram of "abc".
        The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
    Input=  abab
            ab
    Output= [0, 1, 2]
    Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
    */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; cin>>s>>t;
    map<int,int> m,mr; 
    for(char c: t) m[c]++;
    mr=m; int dist=t.length();
    int cnt=m.size(),cntr=0;
    for(int i=0;i<dist;i++) 
    {
        mr[s[i]]--;
        if(mr[s[i]]==0 && m[s[i]]) cntr++;
        else if(mr[s[i]]==-1 && m[s[i]]) cntr--;
    }
    if(cntr==cnt) cout<<0<<'\n';
    for(int i=dist;i<s.length();i++)
    {
        mr[s[i-dist]]++;
        if(mr[s[i-dist]]==0 && m[s[i-dist]]) cntr++;
        else if(mr[s[i-dist]]==1 && m[s[i-dist]]) cntr--;
        mr[s[i]]--;
        if(mr[s[i]]==0 && m[s[i]]) cntr++;
        else if(mr[s[i]]==-1 && m[s[i]]) cntr--;
        if(cntr==cnt) cout<<(i-dist+1)<<'\n';
    }
    return 0;
}