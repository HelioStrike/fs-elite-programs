'''
Given a sorted integer array without duplicates, 
return the summary of its ranges.

Example 1:
    Input= 0 1 2 4 5 7
    Output= ["0->2","4->5","7"]
    Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:
    Input= 0 2 3 4 6 8 9
    Output= ["0","2->4","6","8->9"]
    Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
'''

a=list(map(int,input().split(' ')))
ans=[]
fst=0
for i in range(1,len(a)):
    if(a[i]!=a[i-1]+1):
        if(i-1==fst):
            ans.append(str(a[i-1]))
        else:
            ans.append(str(a[fst])+'->'+str(a[i-1]))
        fst=i
if(fst==len(a)-1):
    ans.append(str(a[len(a)-1]))
else:
    ans.append(str(a[fst])+'->'+str(a[len(a)-1]))
print(ans)