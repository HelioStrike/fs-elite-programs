/*
You have given a orchard splitted into n equal plots in a row.
Some of the plots are planted with orange plants, some are not.

you are not allowed to plant these orange plants in adjacent plots, 
they would compete for water and both would die.

Given a orchard represents with 0's and 1's (0 inidcates not planted 1 indicates planted), 
and a number n, 

return true, if n new orange plants can be planted in it 
without violating the no-adjacent-oranges rule.
else false.


Example 1:
Input= 1 0 0 0 1
1
Output= true

Example 2:
Input= 1 0 0 0 1
2
Output= false


Note:
    It is guaranteed that input array will not violate adjacent rule.
    0<n<size of array
*/