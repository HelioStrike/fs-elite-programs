/*
Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.

___________________
|  1  |  2  |  3  |
| --  | abc | def |
-------------------
|  4  |  5  |  6  |
| ghi | jkl | mno |
-------------------
|  7  |  8  |  9  |
| pqrs| tuv | wxyz|
-------------------

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Your answer should be in lexical order.


*/

#include <bits/stdc++.h>
using namespace std;

int n;
string ms[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
string t;
vector<string> s;

void rec(int pos, string cur)
{
    if(pos==n)
    {
        s.push_back(cur);
        return;
    }
    for(char c: ms[t[pos]-'0'-2]) rec(pos+1,cur+c);
}

int main()
{
    cin>>t; n=t.length();
    rec(0,"");
    for(string k: s) cout<<k<<'\n';
    return 0;
}