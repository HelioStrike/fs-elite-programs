#include <bits/stdc++.h>
using namespace std;

int n,ans;
int con[] = {0,1,6,8,9};
int k=5;
map<int,int> m;

int rev(int c) {
    string s="";
    while(c>0)
    {
        s+=('0'+(c%10));
        c/=10;
    }
    for(int i=0;i<s.length();i++) s[i]=('0'+m[s[i]-'0']);
    int ret=0;
    for(int i=0;i<s.length();i++)
    {
        ret*=10;
        ret+=s[i]-'0';
    }
    return ret;
}

void dfs(int c)
{
    if(c>n) return;
    if(c!=rev(c)) ans++;
    for(int i=0;i<k;i++) dfs(c*10+con[i]);    
}

int main()
{
    m[0]=0,m[1]=1,m[6]=9,m[8]=8,m[9]=6;

    cin>>n;
    for(int i=1;i<k;i++)
    {
        if(con[i]<=n)
        {
            dfs(con[i]);
        }
    }
    cout<<ans<<'\n';
}