/*
 * 
 Rotate an array (of size n) k times left
 
 input : 1 2 3 4 5 6 7
 2
 output: 3 4 5 6 7 1 2
 
 Time complexity : O(n)


 */

#include <bits/stdc++.h>
using namespace std;

int n,x,k;
vector<int> v;
stack<int> s;

int main()
{
    while(cin>>x) v.push_back(x),n++;
    k=*(--v.end()); n--;
    v.pop_back();
    k%=n;
    for(int i=0;i<k;i++) s.push(v[i]);
    for(int i=0;i<n-k;i++) v[i]=v[i+k];
    for(int i=n-1;!s.empty();i--) v[i]=s.top(),s.pop();
    for(int y: v) cout<<y<<' ';
    cout<<'\n';
}