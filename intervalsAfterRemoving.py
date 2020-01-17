'''
Given a sorted list of disjoint intervals, each interval intervals[i] = [a, b] 
represents the set of real numbers x such that a <= x < b.

We remove the intersections between any interval in intervals and the interval toBeRemoved.

Return a sorted list of intervals after all such removals.

Example 1:
	Input=	3
			0 2
			3 4
			5 7
			1 6
	Output= [[0, 1], [6, 7]]

Example 2:
	Input=	1
			0 5
			2 3
	Output= [[0, 2], [3, 5]]
'''

sz=1000
a=[0]*sz
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    for j in range(x,y):
        a[j]+=1
x,y=map(int,input().split())
for j in range(x,y):
    a[j]=0
cur=0
ans=[]
x=-1
while(cur<sz):
    if(x==-1 and a[cur]>0):
        x=cur
    if(x!=-1 and a[cur]==0):
        ans.append([x,cur])
        x=-1
    cur+=1
print(ans)