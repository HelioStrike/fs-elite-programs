/*
 * 
Given a linked list of 0s, 1s and 2s, sort it.

Sample Input : 
0 1 2 2 0 0 1 0 2 2 1 1 -1

Sample Output : 
0 0 0 0 1 1 1 1 2 2 2 2

 * 
 * 
 */
import java.util.Scanner;

class MyListNode {
	public MyListNode next;
	public int data;

	// Creates an empty node.
	public MyListNode() {
		next = null;
		data = Integer.MIN_VALUE;
	}

	// Creates a node storing the specified data.
	public MyListNode(int data) {
		next = null;
		this.data = data;
	}

	// Returns the node that follows this one.
	public MyListNode getNext() {
		return next;
	}

	// Sets the node that follows this one.
	public void setNext(MyListNode node) {
		next = node;
	}

	// Returns the data stored in this node.
	public int getData() {
		return data;
	}

	// Sets the data stored in this node.
	public void setData(int elem) {
		data = elem;
	}

	// Sets the data stored in this node.
	public String toString() {
		return Integer.toString(data);
	}
}

class MyLinkedList {
	// This class has a default constructor:
	public MyLinkedList() {
		length = 0;
	}

	// Length of the linked list
	private int length = 0;
	// This is the only field of the class. It holds the head of the list
	MyListNode head;

	// Insert a node at the end of the list
	public synchronized void insertAtEnd(MyListNode node) {
		if (head == null)
			head = node;
		else {
			MyListNode p, q;
			for (p = head; (q = p.getNext()) != null; p = q)
				;
			p.setNext(node);
		}
		length++;
	}

	// Return a string representation of this collection, in the form
	// "str1" "str2" ....
	public String toString() {
	    // Write Your Code Here
	    String str = "";
	    MyListNode cur = head;
	    while(cur != null)
	    {
	        str += Integer.toString(cur.data) + " ";
	        cur = cur.next;
	    }
	    return str;
	}

	// Return the current length of the list.
	public int length() {
		return length;
	}

}

public class SortLinkedList {

	// static ListNode head;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int tempData = -1;

		// create a linked list
		MyLinkedList list = new MyLinkedList();

		// add nodes one by one till you find end of the character
		while ((tempData = sc.nextInt()) != -1) {
			// add nodes to the linked list
			list.insertAtEnd(new MyListNode(tempData));
		}

		// create a linked list
		MyLinkedList sortedList = new MyLinkedList();

		sortedList.head = sortLinkedList(list.head);

		System.out.println(sortedList.toString());

	}

	static MyListNode sortLinkedList(MyListNode head) {
	    int n = 0;
	    MyListNode cur = head;
	    while(cur != null) { cur = cur.next; n++; } 
	    for(int i=0;i<n;i++)
	    {
	        cur = head;
    	    while(cur.next != null)
    	    {
    	        if(cur.data > cur.next.data)
    	        {
    	            int temp = cur.data;
    	            cur.data = cur.next.data;
    	            cur.next.data = temp;
    	        }
    	        cur = cur.next;
    	        
    	    }
	    }
	    return head;
	    // Write Your Code Here
	}

}
