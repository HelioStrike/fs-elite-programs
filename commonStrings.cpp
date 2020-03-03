/*

Write a Program to find the common string(s) of 2 arrays of strings.
 

Input:ram Laxman krishna
ram Seetha raju

Output: ram

Explanation :
First line of input represents strings(without space) array 1
Second line of input represents strings(without space) array 2
output is common strings between two array i.e ram.
length of 2 arrays of strings can be different also.

print in lexographic order.
*/

m = {}
for s in input().split():
    m[s]=1
ans = []
for s in input().split():
    if m.get(s,0)==1:
        ans.append(s)
ans.sort()
for a in ans:
    print(a)