/*
Given a matrix of 2-Dimensional array of n rows and n columns. 
Print this matrix in snake fashion starting from column n-1 
as shown in the figure below.

Example:
    Input=  3
        1 2 3 
        4 5 6
        7 8 9
    Output= 3 2 1 4 5 6 9 8 7
    Explanation:
        1<-2<-3 
        |
        4->5->6
              |
        7<-8<-9
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        if(i%2) for(int j=0;j<n;j++) cout<<arr[i][j]<<' ';
        else for(int j=n-1;j>=0;j--) cout<<arr[i][j]<<' ';
    }
    cout<<'\n';
    
    return 0;
}