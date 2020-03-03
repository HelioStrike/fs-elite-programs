/*

A binary number is represented as a series of 0's and 1's.
In this challenge, the series will be in the form of a singly-linked list.
Each node instance, a LinkedListNode has a value, val. and a pointer to the 
next node, next. Given a reference to the head of a singly-linked list,
convert the binary number represented to a decimal number.

Example:
        binary linked list
        0->1->0->0->1->1->null
        linked list corresponding to the binary number = (010011) base 2
        decimal number = (19) base 10

Sample Input :
6
0 1 0 0 1 1

Sample Output : 
19

Explanation:
(010011) base 2 = (19) base 10


*/

import java.util.Scanner;

class Node {
    int data;
    Node next;
}

public class BinaryNumberInLinkedList {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

        Node head = new Node(); Node cur = head;
	    /* write your code here */
        for(int i=0;i<n;i++)
        {
            cur.data = sc.nextInt();
            if(i==n-1) {
                cur.next = null;            
            }
            else {
                cur.next = new Node();
                cur = cur.next;
            }
        }
        System.out.println(reduc(head,n));
	}

    static int reduc(Node head, int n) {
        int ans=0;
        while(head != null)
        {
            ans=ans|(head.data);
            ans<<=1;
            head=head.next;
        }
        return ans/2;
    }
}

