'''
You have given an integer array, 
find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:
		Input=  -2 1 -3 4 -1 2 1 -5 4
		Output= 6
		Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, 
which is more subtle.
'''

a=map(int,input().split(' '))
cur=0
ans=-9999999
for x in a:
    cur=max(cur,0)
    cur+=x
    ans=max(ans,cur)
print(ans)