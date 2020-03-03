/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Time Complexity: O(n)

Example 1:
	Input: 1 2 3
	Output: [1, 2, 4]
	Explanation: The array represents the integer 123.

Example 2:
	Input: 4 3 2 1
	Output: [4, 3, 2, 2]
	Explanation: The array represents the integer 4321.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  vector <int> v;
  string str;
  getline(cin, str);

  for(int i=0; i<str.length(); i+=2)
    v.push_back(str[i]-'0');

  int i = v.size() - 1;

  while(v[i] == 9) v[i] = 0, i--;

  
  if(i==-1) cout << 1 << "";   // when 9, 999, etc are inputs, the next num is 10, 1000 etc
  else v[i] += 1;


  for(auto i: v) cout << i << "";

  return 0;
}