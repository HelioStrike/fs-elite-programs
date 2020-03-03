/*
 * 
create a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

Sample Input:
push 20
push 15
pop
push 44
push 80
getmin

Sample Output :
20


Sample Input:
push 40
push 30
push 85
push 64
pop
pop
top

Sample Output :
30


 */

#include <bits/stdc++.h>
using namespace std;

int p=1,x,mn=INT_MAX;
stack<int> a;
string s;

int main()
{
    a.push(INT_MAX);
    while(cin>>s)
    {
        if(s=="top")
        {
            cout<<a.top()<<'\n';
            break;
        }
        else if(s=="getmin")
        {
            cout<<mn<<'\n';
            break;
        }
        else if(s=="push")
        {
            cin>>x; 
            if(x<=mn) 
            {
                a.push(mn);
                mn=x;           
            }
            a.push(x);
        }
        else if(s=="pop")
        {
            if(mn==a.top())
            {
                a.pop();
                mn=a.top();
            }
            a.pop();
        }
    }
}k