/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack and prints it.
top() -- Get the top element and prints it.
empty() -- Return whether the stack is empty.

Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Note : can you do using one queue

Example-1:
push 1
push 2
pop
2       // print deleted element
top
1       // print top element
push 5
top
5       //print top element 
empty
false   //print boolean value whether the stack is empty or not
exit    //end of the operations


Example-1:
push 1
push 2
push 3
pop
3       // print deleted element
pop
2       // print deleted element
top
1       // print top element
pop
1       // print deleted element
empty
true    //print boolean value whether the stack is empty or not
exit    // end of opeartions
*/