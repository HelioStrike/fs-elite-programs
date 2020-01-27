/*
Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. 
(Trailing spaces are not allowed).

Each word would be put on only one column and that in one column there will be only one word.

Example 1:
	Input=  HOW ARE YOU
	Output= HAY,ORO,WEU,
	Explanation: Each word is printed vertically. 
	 "HAY"
	 "ORO"
	 "WEU"

Example 2:
	Input=  TO BE OR NOT TO BE
	Output= TBONTB,OEROOE,   T,
	Explanation: Trailing spaces is not allowed. 
	"TBONTB"
	"OEROOE"
	"   T"

Example 3:
	Input=  CONTEST IS COMING
	Output= CIC,OSO,N M,T I,E N,S G,T,

NOTE: String can contains both uppercase and lowercase alphabets 
Take care of OUTPUT format.
*/

#include <bits/stdc++.h>
using namespace std;

int n,mx;
vector<string> ss,ans;
string s;

int main()
{
    while(cin>>s)
    {
        ss.push_back(s);
        mx=max(mx,(int)s.length());
    }
    for(int i=0;i<mx;i++)
    {
        s="";
        for(string t: ss)
        {
            if(i<t.length()) s+=t[i];
            else s+=' ';
        }
        ans.push_back(s);
    }
    for(string t: ans)
    {
        int m=t.length()-1;
        while(t[m]==' ') m--;
        for(int i=0;i<=m;i++) cout<<t[i];
        cout<<',';
    }
    cout<<'\n';
}