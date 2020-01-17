'''
You are given some lists of areas where the first area of each list includes 
all other areas in that list.

Naturally, if an area A contains another area B then A is bigger than B. 
Also by definition an area A contains itself.

Given two areas area1, area2, find out the smallest area that contains both of them.
If you are given areas a1, a2 and a3 such that a1 includes a3, 
it is guaranteed there is no a2 such that a2 includes a3.

It's guaranteed the smallest area exists.

Example 1:
Input=	5
		Earth-North America-South America
		North America-United States-Canada
		United States-New York-Boston
		Canada-Ontario-Quebec
		South America-Brazil
		Quebec			//area-1
		New York		//area-2
Output=North America
 
Build family tree from offsprings to their parents;
Use a HashSet to construct ancestry history of area1;
Retrieve ancestry of area2 by family tree till find the first common ancestry 
in ancestry history of area1.
'''

n=int(input())
ps = {}
for _ in range(0,n):
    pls = input().split('-')
    for pl in pls[1:]:
        ps[pl]=pls[0]

vis = {}
p1 = input()
p2 = input()

x = p1
while x in ps.keys():
    vis[x] = 1
    x = ps[x]
vis[x] = 1


x = p2
while not x in vis.keys():
    if x not in ps.keys():
        break
    x = ps[x]

print(x)