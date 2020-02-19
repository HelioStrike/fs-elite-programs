/*
Given two strings A and B, 
return true if they are equal when both are typed into empty text editors
else false.
$ means a backspace character.

Example 1:
    Input= ab$c ad$c
    Output= true
    Explanation: Both A and B become "ac".
    
Example 2:
    Input= b$$ c$d$
    Output= true
    Explanation: Both A and B become "".

Example 3:
    Input= $$c $a$c
    Output= true
    Explanation: Both A and B become "c".

Example 4:
    Input= $c b
    Output= false
    Explanation: A becomes "c" while B becomes "b".


Can you solve it in O(N) time and O(1) space?
*/