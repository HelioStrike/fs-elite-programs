/*
Given a string, that is a ternary expressions or nested ternary expression, 
calculate the result of the ternary expression. 

You can always assume that the given string is valid expreession and 
only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

Each number will contain only one digit.
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.

Example 1:
	Input=	F?F:T
	Output=	T

Explanation: If FALSE, then result is TRUE; otherwise result is FALSE.

Example 2:
	Input=	T?F?3:4:2
	Output=	4

Explanation: given T -> true, so F?3:4 -> F is false, so output is 4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.length(),a,b;
    stack<char> st;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==':') continue;
        else if((s[i]>='0' && s[i]<='9') || s[i]=='T' || s[i]=='F') st.push(s[i]);
        else
        {
            a=st.top(); st.pop();
            b=st.top(); st.pop();
            if(s[i-1]=='T') st.push(a);
            else st.push(b);
            i--;
        }
    }
    cout<<st.top()<<'\n';
}