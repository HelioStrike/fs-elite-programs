/*
You will be given a string, 
find out the length of the longest repeating substring(s). 
Return 0 if no repeating substring exists.

 Example 1:
	Input=	abcd
	Output=0
	Explanation: There is no repeating substring.

Example 2:
	Input=	abbaba
	Output=2
	Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice.

Example 3:
	Input=	aabcaabdaab
	Output=3
	Explanation: The longest repeating substring is "aab", which occurs 3 times.

Example 4:
	Input=	aaaaa
	Outpu=4
	Explanation: The longest repeating substring is "aaaa", which occurs twice.
*/

#include <bits/stdc++.h>
#define P 31
#define M 1000000007
using namespace std;

int main()
{
    string s; cin>>s; int n=s.length();
    int ans=0;
    map<long long,pair<int,int>> cnts;
    for(int i=0;i<n;i++)
    {
        long long hash=0;
        for(int j=i;j<n;j++)
        {
            hash=((hash+s[j]-'a'+1)*P)%M;
            cnts[hash].first++;
            cnts[hash].second=j-i+1;
        }
    }
    for(auto p: cnts) {
        if(p.second.first>1) ans=max(ans,p.second.second);
    }
    cout<<ans<<'\n';
}