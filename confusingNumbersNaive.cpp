/*
  This is brute force algorithm which checks each number
  from 1 to N for its "Confusing Property"

  Not every number is checked.
  The numbers comprising of only {0, 1, 6, 8, 9} are checked

  How efficient is it?
  Fast output (t<1sec) for 10^6 or less N
  (1<t<5) sec for 10^7
*/

#include <bits/stdc++.h>
using namespace std;


map <int, int> m = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};


// This function checks whether all the digits of a given number are in mapkeys or not
bool valid(int x)
{
  while(x>0)
  {
    if(m.find(x % 10) == m.end())
      return false;
    x /= 10;
  }
  return true;
}

// This function gives count of all the confusing Numbers
int confusingNums(int n)
{
    int count = 0;

    // We start with 6 since we 0, 1 are indiffent in their 180* view but 6 becomes 9
    // and so on
    for(int i=6; i<=n; i++){
      if(! valid(i)) continue;  // check if all digits are valid
      int newnum = 0;
      int temp = i; // for iteration
      while(temp > 0)
      {
        newnum = newnum*10 + m[temp%10];
        temp /= 10;
      }

      if(newnum != i) {
        // Uncomment the below line to see all the Confusing pairs
        // cout << i << " " << newnum << endl;
        count++;
      }
    }
    return count;
}



int main()
{
  int n; cin >> n;
  int count = confusingNums(n);
  cout << count << endl;

}
