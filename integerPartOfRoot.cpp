/*
FInd the square root  of a given number using binary search concept
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n; cin>>n;
    float l=0,r=1000,m;
    for(int i=0;i<1000;i++)
    {
        m=(l+r)/2;
        if(m*m>n) r=m;
        else l=m;
    }
    cout<<(int)m<<'\n';
}