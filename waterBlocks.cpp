/*
A Kid is arranging a structure using building blocks, 
by placing one on another or adjacent to it.
           ___
here each |___| represents one building block.

The following structure made up of some building blocks

                      ___
                  ___|___|    ___
                 |___|___|_w_|___|___              ___
              ___|___|___|___|___|___| w   _w_  w |___| 
          ___|___|___|___|___|___|___|_w__|___|_w_|___|____________

            0  1   3   4   2   3    2   0   1   0   2

After that structure is made, kid pour water on it.
How much amount of water can be stored by the structure.


            
Example:
    Input= 0 1 3 4 2 3 2 0 1 0 2
    
    Output= 6
    
    Explanation:
    In the above structure,  6 units of water (w represents the water in the structure)
    can be stored.
*/

#include <bits/stdc++.h>
#define N 1000
using namespace std;

int n,ans,a[N],l[N],r[N];

int main()
{
    while(cin>>a[++n]);
    for(int i=1;i<=n;i++) l[i]=max(a[i],l[i-1]);
    for(int i=n;i>=1;i--) r[i]=max(a[i],r[i+1]);
    for(int i=1;i<=n;i++) ans+=min(l[i],r[i])-a[i];
    cout<<ans<<'\n';
}