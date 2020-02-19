/*
/*
 * 
Given a list of flight tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the travel plan in order. All of the tickets belong to a man who departs from BZA.
Thus, the travel plan must begin with BZA.

Note:

If there are multiple valid itineraries, 
you should return the travel plan that has the smallest lexical order when read as a single string. 
For example, the travel plan ["BZA", "LGA"] has a smaller lexical order than ["BZA", "LGB"].

All airports are represented by three capital letters.
You may assume all tickets form at least one valid travel plan.

Example 1:

Input:4
DEL HYD
BZA DEL
BLR MAA
HYD BLR

Output: ["BZA", "DEL", "HYD", "BLR", "MAA"]

Example 2:

Input:5
BZA BLR
BZA CCU
BLR CCU
CCU BZA
CCU BLR
Output: ["BZA","BLR","CCU","BZA","CCU","BLR"]

              
             
*/
