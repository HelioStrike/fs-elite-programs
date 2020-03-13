/*
An encoded string S is given.  
To find and write the decoded string to a tape, 
the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.


Example 1:
    Input:  kmit2ngit3
            10
    Output: o
    Explanation: 
            The decoded string is "kmitkmitngitkmitkmitngitkmitkmitngit".
            The 10th letter in the string is "o".

Example 2:
    Input:  ha22
            5
    Output: h
    Explanation: 
            The decoded string is "hahahaha".  
            The 5th letter is "h".

Example 3:
    Input:  a2345678999999999999999
            1
    Output: a
    Explanation: 
            The decoded string is "a" repeated 8301530446056247680 times.  
            The 1st letter is "a".
            
            
NOTE: If No Such Index K in decoded string, print "$"
*/

#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c) { return c>='0' && c<='9'; }

int main()
{
    string s; cin>>s;
    long long n; cin>>n;
    long long c=0;
    for(char x: s)
    {
        if(isDigit(x)) c=c*(x-'0');
        else c++;
    }
    if(n<1)
    {
        cout<<"$";
        return 0;
    }
    int i=s.length();
    while(--i)
    {
        if(!isDigit(s[i])) break;
        if(s[i]=='0')
        {
            cout<<"$";
            return 0;
        }
    }
    i=s.length();
    while(--i)
    {
        n=n%c;
        if(n==0 && !isDigit(s[i]))
        {
            cout<<s[i]<<'\n';
            return 0;
        }
        if(isDigit(s[i])) c/=(s[i]-'0');
        else c--;
    }
    if(n==0) cout<<s[0]<<'\n';

    return 0;
}