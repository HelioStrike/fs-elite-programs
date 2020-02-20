/*
You will be given two strings A and B of the same length, 
determine whether you can convert A into B by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in A
to any other lowercase English character.

Return true if and only if A and B are equal after conversion.


Example 1:
	Input= aabcc ccdee
	Output= true
	Explanation: 
	Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. 
	Note that the order of conversions matter.

Example 2:
	Input= football ballfoot
	Output= false
	Explanation: There is no way to transform A to B.
 

Note:
Both A and B contain only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,t; cin>>s>>t; int n=s.length();
    map<char,char> m;
    for(char c='a';c<='z';c++) m[c]=c;
    for(int i=0;i<n;i++) if(m[s[i]]!=t[i]) m[s[i]]=t[i];
    for(int i=0;i<n;i++) if(m[s[i]]!=t[i]) { cout<<"false"<<'\n'; return 0; }
    cout<<((m.size()<26)?"true":"false)<<'\n';
    return 0;
}
