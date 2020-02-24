/*
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), 
where h is the height of the person and 
k is the number of people in front of this person who have a height greater than or equal to h.

Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

    Input:6
    7 0
    4 4
    7 1
    5 0
    6 1
    5 2
    
    Output:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

#include <bits/stdc++.h>
#define N 1110
using namespace std;

struct ppl { int h,k; } ps[N];
int n,ans[N];

bool cmp(ppl a,ppl b)
{
    return a.h>b.h || (a.h==b.h && a.k<b.k);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>ps[i].h>>ps[i].k;
    sort(ps,ps+n,cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>ps[i].k;j--) ans[j]=ans[j-1];
        ans[ps[i].k]=i;
    }
    for(int i=0;i<n;i++) cout<<ps[ans[i]].h<<' '<<ps[ans[i]].k<<'\n';
    return 0;
}