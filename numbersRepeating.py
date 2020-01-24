'''
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.

Example 1:
    Input: 1 2 3 1
    Output: true

Example 2:

Input: 1 2 3 4
Output: false
Example 3:

Input: 1 1 1 3 3 4 3 2 4 2
Output: true
 
NOTE: Time complexity Should be O(nlogn) or O(n)
'''

a=map(int,input().split(' '))
a=sorted(a)
ans=False
for i in range(0,len(a)-1):
    if a[i]==a[i+1]:
        ans=True
        break
print(ans)