/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand
operation which turns the water at position (row, col) into a land.

Given a list of positions to operate, count the number of islands after each addLand operation.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
vertically. You may assume all four edges of the grid are all surrounded by water.

I/O Format:
Input Format:   first line conatins, 3 integers, indicates m, n, no.of.positions(p)
                next 'p' lines, each 2 integers, indicates position to add land.
Output Format: 'p' integers, indicates the `number of islands` after each addLand operation

Example-1:
    Input:  3 3 4
            0 0
            0 1
            1 2
            2 1
    Output: 1 1 2 3
    
    Explanation:
    Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
        0 0 0
        0 0 0
        0 0 0
    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
        1 0 0
        0 0 0   Number of islands = 1
        0 0 0
    Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
        1 1 0
        0 0 0   Number of islands = 1
        0 0 0
    Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
        1 1 0
        0 0 1   Number of islands = 2
        0 0 0
    Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
        1 1 0
        0 0 1   Number of islands = 3
        0 1 0

Example-2:
    Input:  2 2 3
            0 0
            1 1
            1 0
    Output: 1 2 1
    
    Explanation:
    Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
        0 0 
        0 0 
    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
        1 0 
        0 0    Number of islands = 1
    Operation #2: addLand(1, 1) turns the water at grid[1][1] into a land.
        1 0 
        0 1    Number of islands = 2
    Operation #3: addLand(1, 0) turns the water at grid[1][2] into a land.
        1 0 
        1 1    Number of islands = 1
*/

#include <bits/stdc++.h>
#define N 100
using namespace std;

int n,m,k,x,y,p[N*N];
bool mp[N][N];

int f(int x) { return x==p[x]?x:p[x]=f(p[x]); }

int id(int i,int j) { return i*m+j; }

int main()
{
    cin>>n>>m>>k; n++,m++;
    for(int i=0;i<=(n+1)*(m+1);i++) p[i]=i;
    for(int i=0;i<k;i++) 
    {
        cin>>x>>y; x++,y++;
        mp[x][y]=1;
        if(mp[x-1][y]) p[f(id(x-1,y))]=f(id(x,y));
        if(mp[x+1][y]) p[f(id(x+1,y))]=f(id(x,y));
        if(mp[x][y-1]) p[f(id(x,y-1))]=f(id(x,y));
        if(mp[x][y+1]) p[f(id(x,y+1))]=f(id(x,y));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j] && id(i,j)==p[f(id(i,j))]) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    cout<<'\n';
}

/*
//Faster but passes 5/6 cases because of some bug

#include <bits/stdc++.h>
#define N 100
using namespace std;

int n,m,k,x,y,ans,p[N*N];
bool mp[N][N];

int f(int x) { return x==p[x]?x:p[x]=f(p[x]); }

int id(int i,int j) { return i*m+j; }

int main()
{
    cin>>n>>m>>k; n++,m++;
    for(int i=0;i<=(n+1)*(m+1);i++) p[i]=i;
    for(int i=0;i<k;i++) 
    {
        cin>>x>>y; x++,y++;
        if(mp[x][y]) continue;
        mp[x][y]=1;
        map<int,int> ps;
        if(mp[x-1][y] && f(id(x-1,y))!=f(id(x,y))) ps[f(id(x-1,y))]++,p[f(id(x-1,y))]=f(id(x,y));
        if(mp[x+1][y] && f(id(x+1,y))!=f(id(x,y))) ps[f(id(x+1,y))]++,p[f(id(x+1,y))]=f(id(x,y));
        if(mp[x][y-1] && f(id(x,y-1))!=f(id(x,y))) ps[f(id(x,y-1))]++,p[f(id(x,y-1))]=f(id(x,y));
        if(mp[x][y+1] && f(id(x,y+1))!=f(id(x,y))) ps[f(id(x,y+1))]++,p[f(id(x,y+1))]=f(id(x,y));
        ans++;
        for(auto l: ps) ans--;
        cout<<ans<<'\n';
    }
    cout<<'\n';
}
*/