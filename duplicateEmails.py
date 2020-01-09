'''
Given a list of emails which consists of a local name and a domain name, separated by the @ sign.
For example, in john@kmit.com ,  john is the local name, and kmit.com is the domain name.
Besides lowercase letters, these emails may contain '.' s or '+' s.

If you add periods ( '.' ) between some characters in the local name part of an email address, 
mail sent there will be forwarded to the same address without dots in the local name.  

For example, "john.z@kmit.com" 
and "johnz@kmit.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ( '+' ) in the local name, everything after the first plus sign will be ignored. 
This allows certain emails to be filtered, for example  m.y+name@email.com  will be forwarded to  my@email.com
(Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.
Given a list of emails , we send one email to each address in the list.  

How many different addresses actually receive mails? 
 
Example 1:
Input:3
test.email+venkaty@kmit.com
test.e.mail+venkat.sai@kmit.com
testemail+gopi@kmit.eng.com

Output: 2
Explanation: "testemail@kmit.com" and "testemail@kmit.eng.com" actually receive mails
'''

m = {}
for i in range(int(input())):
    a=input().split('@')
    b=a[0].split('+')[0]
    b="".join(b.split('.'))
    m[b+a[1]]=1
print(len(m.keys()))