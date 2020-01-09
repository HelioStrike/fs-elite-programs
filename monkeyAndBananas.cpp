/*
There's a tree, a mokey, and several fruits. 

Positions are represented by the cells in a 2D grid. 

Your goal is to find the minimal distance for the monkey to 
collect all the fruits and put them under the tree one by one. 

The monkey can only take at most one fruit at one time 
and can move in four directions - up, down, left and right, to the adjacent cell. 
The distance is represented by the number of moves.

Example 1:
    Input=  5
            7
            2 2
            4 4
            2
            3 0
            2 5
    Output= 12
    Input Format:
        Height : 5
        Width : 7
        Tree position : [2,2]
        Monkey : [4,4]
        Number of Fruits : 2
        Fruits : [[3,0], [2,5]]
*/
#include <bits/stdc++.h>
using namespace std;

int n,m,tx,ty,mx,my,nb;
int bx[100],by[100];
int tot,ans=INT_MAX;

int main()
{
    cin>>n>>m>>tx>>ty>>mx>>my;
    cin>>nb;
    for(int i=0;i<nb;i++)
    {
        cin>>bx[i]>>by[i];
        tot+=2*(abs(bx[i]-tx)+abs(by[i]-ty));
    }
    for(int i=0;i<nb;i++) ans=min(ans,tot-(abs(bx[i]-tx)+abs(by[i]-ty))+(abs(bx[i]-mx)+abs(by[i]-my)));
    cout<<ans<<'\n';
}