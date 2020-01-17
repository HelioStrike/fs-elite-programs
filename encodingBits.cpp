/*
 
Given a non-negative integer, Return its encoding number as string.

The encoding is done by converting the integer to a string using 
a secret function that you should deduce from the following table:
-----------
| n | f(n)|
|---------|
| 0 |     |
| 1 | 0   |
| 2 | 1   |
| 3 | 00  |
| 4 | 01  |
| 5 | 10  |
| 6 | 11  |
| 7 | 000 |
-----------

Example 1:
	Input=	23
	Output= 1000

Example 2:
	Input=	107
	Output= 101100

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int car=1,cur=0;
    while(car<=n)
    {
        n-=car;
        car*=2;
        cur++;
    }
    int bts=0;
    stack<int> s;
    while(n)
    {
        s.push(n&1);
        n>>=1;
        bts++;
    }
    for(int i=0;i<cur-bts;i++) s.push(0);
    while(!s.empty()) cout<<s.top(),s.pop();
    cout<<'\n';
}