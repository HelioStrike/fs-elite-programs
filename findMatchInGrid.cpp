/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 

The same cell should not be used more than once.

Example:

    input=  3
            4
            A B C E
            S F C S
            A D E E
            ABCCED
    output= true
    
    input=  3
            4
            A B C E
            S F C S
            A D E E
            ABCB
    output= false

*/

#include <bits/stdc++.h>
#define N 10
using namespace std;

int n,m,k,pos,vis[N][N];
char a[N][N];
string s;
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool dfs(int x,int y,int c)
{
    if(x>=n || x<0 || y>=m || y<0 || a[x][y]!=s[c] || vis[x][y]) return false;
    vis[x][y]=1;
    if(c+1==k) { return true; }
    for(int i=0;i<4;i++)
    {
        if(dfs(x+dirs[i][0],y+dirs[i][1],c+1)) return true;;
    }
    vis[x][y]=0;
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    cin>>s; k=s.length();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(pos) break;
            pos=dfs(i,j,0);
        }
        if(pos) break;
    }
    cout<<(pos?"true":"false")<<'\n';
}