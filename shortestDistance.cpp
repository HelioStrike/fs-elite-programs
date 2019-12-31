/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.

Input:3 5
1 0 2 0 1
0 0 0 0 0
0 0 1 0 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
*/

#include <bits/stdc++.h>
using namespace std;

//Multi-point BFS

int main()
{
    //Take input and store the location of each building
    int n,m,k=0; cin>>n>>m;
    int mp[n][m];
    vector<pair<int,int> > pos;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]==1)
            {
                k++;
                pos.push_back({i,j});
            }
        }
    }
    tuple<int,int,int> c;
    int x,y,d;
    int vis[n][m],dist[n][m];
    memset(dist,0,sizeof(dist));
    //Multi-point
    for(auto p: pos)
    {
        //BFS
        memset(vis,0,sizeof(vis));
        queue<tuple<int,int,int> > q;
        q.push(make_tuple(0,p.first,p.second));
        while(!q.empty()) {
            c=q.front(); q.pop();
            d=get<0>(c),x=get<1>(c),y=get<2>(c);
            if(vis[x][y] || mp[x][y]==2 || (mp[x][y]==1 && d!=0)) continue;
            vis[x][y]=1;
            //Add depths to dist matrix in each BFS
            dist[x][y]+=d;
            if(x!=n-1) q.push(make_tuple(d+1,x+1,y));
            if(x!=0) q.push(make_tuple(d+1,x-1,y));
            if(y!=m-1) q.push(make_tuple(d+1,x,y+1));
            if(y!=0) q.push(make_tuple(d+1,x,y-1));
        }
    }

    //Get and print minimum dist[x][y] value
    int maxm=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]==0&& dist[i][j]<maxm)
            {
                maxm=dist[i][j];
            }
        }
    }
    
    cout<<maxm<<'\n';
}