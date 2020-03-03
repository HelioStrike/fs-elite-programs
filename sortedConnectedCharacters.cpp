/*

Given a string s, and a list of pair's of indices where pair[i] = [x, y] 
indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:
Input=  dcab
		2
		0 3
		1 2
Output= bacd
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Example 2:
Input=  dcab
		3
		0 3
		1 2
		0 2
Output= abcd
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:
Input=  cba
	    2
		0 1
		1 2
Output: abc
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 
Constraints:
1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

#include <bits/stdc++.h>
#define N 100010
using namespace std;

string s;
int k,x,y,sl,p[N];
priority_queue<char, vector<char>, std::greater<char> > st[N];
map<int,int> m;

int f(int x) { return x==p[x]?x:p[x]=f(p[x]); }

int main()
{
    cin>>s>>k; sl=s.length();
    for(int i=1;i<N;i++) p[i]=i;
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        p[f(x)]=f(y);
    }
    for(int i=0;i<sl;i++) { st[f(i)].push(s[i]); }
    for(int i=0;i<sl;i++)
    {
        cout<<st[p[i]].top();
        st[p[i]].pop();
    }
    return 0;
}