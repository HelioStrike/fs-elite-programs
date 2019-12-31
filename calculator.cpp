/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ) , 
the plus + or minus sign - , non-negative integers and empty spaces .

The expression string contains only non-negative integers, + , - , * , / operators,
open '(' and closing parentheses ')' and empty spaces . The integer division
should truncate toward zero.

You may assume that the given expression is always valid. 
All intermediate results will be in the range of [-2147483648, 2147483647] .

IO Format:
 Input Format:   A String S, contains the expression
 Output Format:  An integer, indicates the value of the expression

Example-1:
    input =  1 + 1
    output = 2

Example-2:
    input = 6-4 / 2 
    output = 4

Example-3:
input = 2*(5+5*2)/3+(6/2+8)
output = 21

Example-4:
    input = (2+6* 3+5- (3*14/7+2)*5)+3
    output = -12

Note: Do not use the 'eval' built-in library function.
*/

#include <bits/stdc++.h>
using namespace std;

char c;
stack<int> s;
queue<int> q,qt;
int cint,x;

int prec(char op)
{
    if(op=='/' || op=='*') return 1;
    return 0;
}

bool isop(char op)
{
    if(op=='/' || op=='+' || op=='*' || op=='-') return 1;
    return 0;
}

int main()
{
    bool empty=1;
    while((c=getchar())!='\n')
    {
        if(c==' ') continue; 
        if(c>='0' && c<='9') { cint=cint*10+(c-'0'); empty=0; }
        else
        {
            if(cint) q.push(cint),cint=0,qt.push(0);
            if(c=='(') s.push(c);
            else if(c==')')
            {
                while(s.top()!='(')
                {
                    q.push(s.top()); s.pop(); qt.push(1);
                }
                s.pop();
            }
            else
            {
                while(!s.empty() && isop(s.top()) && prec(s.top())>=prec(c)) {
                    q.push(s.top()); s.pop(); qt.push(1);
                }
                s.push(c);
            }
        }
    }
    if(empty) { cout<<0<<'\n'; return 0; }
    if(cint) q.push(cint),qt.push(0);
    while(!s.empty()) {
        q.push(s.top()); s.pop(); qt.push(1);
    }
    
    /*
    while(!q.empty()) {
        if(!isop(q.front())) cout<<q.front()<<' '; 
        else cout<<(char)q.front()<<' ';
        q.pop();
    } cout<<'\n';
    */
    
    stack<int> st; int ty;
    while(!q.empty())
    {
        x=q.front(); q.pop();
        ty=qt.front(); qt.pop();
        if(ty)
        {
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            if(x=='*') st.push(a*b);
            if(x=='/') st.push(b/a);
            if(x=='-') st.push(b-a);
            if(x=='+') st.push(a+b);
            //cout<<a<<' '<<b<<' '<<st.top()<<'\n';
        }
        else
        {
            st.push(x);
        }
    }
    cout<<st.top()<<'\n';
    
    return 0;
}