/*
Given a string s, return the maximum number of ocurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.
 

Example 1:
	Input=  aababcaab	//given string
			2			//Maximun Letters
			3			//Minimum Size
			4			//Maximum Size
	Output= 2
	Explanation: Substring "aab" has 2 ocurrences in the original string.
	It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:
	Input=  aaaa
			1
			3
			3
	Output= 2
	Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

Example 3:
	Input=  aabcabcab
			2
			2
			3
	Output= 3

Example 4:
	Input=  abcde
			2
			3
			3
	Output= 0
*/

#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define P 31
using namespace std;

string s,t;
int ans;
ll n,mc,mx,mn,hsh;
map<ll,int> m;

int main()
{
    cin>>s>>mc>>mn>>mx; n=s.length();
    for(int i=0;i<n-mn+1;i++)
    {
        map<int,int> cm;
        int cd=0;
        t=""; hsh=0;
        for(int j=i;j<min(n,i+mx);j++)
        {
            hsh=((hsh+s[j]-'a'+1)*P)%MOD;
            if(!cm[s[j]]) cd++;
            if(cd>mc) break;
            cm[s[j]]++;
            if(j-i+1>=mn && j-i+1<=mx) m[hsh]++;
        }
    }
    for(auto p: m) ans=max(ans,p.second);
    cout<<ans<<'\n';
}