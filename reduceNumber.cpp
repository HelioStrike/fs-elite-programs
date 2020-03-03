/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:
	Input:	8
	Output:	 3
	Explanation:
		8 -> 4 -> 2 -> 1

Example 2:
	Input:	7
	Output:	 4
	Explanation:
		7 -> 8 -> 4 -> 2 -> 1
		or
		7 -> 6 -> 3 -> 2 -> 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int ans=0;
    while(n!=1)
    {
        if(n&1)
        {
            if(__builtin_popcount(n+1)<__builtin_popcount(n-1)) n++;
            else n--;
            ans++;
        }
        n>>=1;
        ans++;
    }
    cout<<ans<<'\n';

    return 0;
}