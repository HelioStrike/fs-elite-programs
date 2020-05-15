/*
In a Packet of Tokens, every token has a unique integer.  
You can order tokens of the Packet in any order you want.

Initially, all the tokens are hidden (closed) in the Packet.

Now, you do the following steps repeatedly, until all tokens are shown (opened):

Take the top token of the Packet, show it, and take it out of the Packet.

If there are still tokens in the Packet, put the next top token of the Packet at the bottom of the Packet.
If there are still hidden tokens, go back to previous step.  Otherwise, stop.
Return an ordering of the Packet that would show the tokens in increasing order.

The first entry in the answer is considered to be the top of the Packet.

 

Example 1:

Input: 28 24 22 13 14 16 18
Output: 13 24 14 22 16 28 18

Explanation: 
We get the Packet in the order [28,24,22,13,14,16,18] (this order doesn't matter), and reorder it.
After reordering, the Packet starts as [13,24,14,22,16,28,18], where 13 is the top of the Packet.
We show 13, and move 24 to the bottom.  Packet Now-> [14,22,16,28,18,24].
We show 14, and move 22 to the bottom.  Packet Now-> [16,28,18,24,22].
We show 16, and move 28 to the bottom.  Packet Now-> [18,24,22,28].
We show 18, and move 24 to the bottom.  Packet Now-> [22,28,24].
We show 22, and move 28 to the bottom.  Packet Now-> [24,28].
We show 24, and move 28 to the bottom.  Packet Now-> [28].
We show 28.
Since all the tokens shown are in increasing order, the answer is correct.
*/

#include <bits/stdc++.h>
using namespace std;

int n,x,cur;
vector<int> v;
bool show;

int main()
{
    while(cin>>x) v.push_back(x),n++;
    sort(v.begin(),v.end());
    int ans[n];
    queue<int> q; for(int i=0;i<n;i++) q.push(i);
    while(!q.empty())
    {
        x=q.front(); q.pop();
        ans[x]=v[cur]; cur++;
        if(q.empty()) break;
        x=q.front(); q.pop(); q.push(x);        
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
}