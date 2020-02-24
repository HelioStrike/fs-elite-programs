/*
In operating system, process scheduling is an important concept.
CPU need to schedule the given processes given as an array of chars . 

Array contains capital letters A to Z where different letters represent different processes.

Scheduling the processes have to follow the given rules:
    - processes could be done without original order. 
    - Each process could be done in one interval. 
    - For each interval, CPU could finish one process or just be idle.

There is a non-negative cooling interval n that means between two same processes, 
there must be at least n intervals that CPU can assign with different processes 
or just be idle.

You need to return the least number of intervals the CPU will take to finish all 
the given processes.

Example:
    Input=  A A A B B B
            2
    Output= 8
    Explanation: 
        A -> B -> idle -> A -> B -> idle -> A -> B.
*/