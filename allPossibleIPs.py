'''
 Given a string containing only digits, restore it by returning all possible valid IP address 
 combinations.
Note : print result in sorted order (ascending)
Example:

Input: 25525511135
Output: ["255.255.11.135", "255.255.111.35"]
'''

s=input()
ans=[]
n=len(s)

def checkValid(cur):
    for tok in cur.split('.'):
        if str(int(tok)) != tok:
            return False
    return True
    
def rec(cur,idx,cnt):
    if cnt == 3:
        if int(s[idx:]) >= 0 and int(s[idx:]) <= 255 and checkValid(cur+s[idx:]):
            ans.append(cur+s[idx:])   
        return
    for i in range(1,4):
        if idx+i < n and int(s[idx:idx+i]) >= 0 and int(s[idx:idx+i]) <= 255:
            rec(cur+s[idx:idx+i]+".",idx+i,cnt+1)

rec('',0,0)
print(sorted(ans))