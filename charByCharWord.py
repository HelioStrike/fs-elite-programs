'''
Given a list of strings words representing an English Dictionary, find the longest word 
in given input, that can be built one character at a time by other words in words. 

If there is more than one possible answer, 
return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

Example 1:
    Input=  w wo wor worl world
    Output= world
    Explanation: 
    The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
    Input=  a banana app appl ap apply apple
    Output= apple
    Explanation: 
    Both "apply" and "apple" can be built from other words in the dictionary. 
    However, "apple" is lexicographically smaller than "apply".
'''

ws=sorted(input().split(' '))
m={}
for w in ws:
    m[w]=0
    if(w[:-1] in ws):
        m[w]=m[w[:-1]]+1
ans=[]
for w in ws:
    if(m[w]==len(w)-1):
        ans.append(w)
maxm=0
for a in ans:
    maxm=max(maxm,len(a))
for a in ans:
    if len(a)==maxm:
        print(a)
        break