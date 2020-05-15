/*
 Given a linked list and two positions 'm' and 'n'.
 The task is to rotate the sublist from position m to n, to the right by k places.


Sample Input : 
11 12 13 14 15 16 -1
2 5 2

Sample Output : 
11 14 15 12 13 16

Explanation:
Rotate the sublist 12 13 14 15 towards right 2 times
then the modified list are: 11 14 15 12 13 16


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
		String result = "";
		if (head == null) {
			return result + "";
		}
		result = result + head.getData();
		MyListNode temp = head.getNext();
		while (temp != null) {
			result = result + " " + temp.getData();
			temp = temp.getNext();
		}
		return result + "";
	}

	// Return the current length of the list.
	public int length() {
		return length;
	}

}

public class RotateSubList {

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
		int m = sc.nextInt();
		int n = sc.nextInt();
		int k = sc.nextInt();

		rotateSubList(list.head, m, n, k, list);
        MyListNode cur = list.head;
        while(cur!=null)
        {
            System.out.print(cur.data+" ");
            cur = cur.next;
        }
	}

	static void rotateSubList(MyListNode A, int m, int n, int k, MyLinkedList list) {
		MyListNode chead = A;
        k=k%(n-m+1);
        if(k==0) return;
		MyListNode headnxt = chead.next;
		MyListNode chnge = chead,chprev = null;
		for(int i=0;i<=n-k-1;i++) 
		{
		    chprev = chnge;
    		chnge=chnge.next;
		}
		MyListNode chngr = chnge,chrprev = null;
		for(int i=0;i<k;i++) 
		{
		    chrprev = chngr;
    		chngr=chngr.next;
		}
		if(m == 1)
		{
            chrprev.next = list.head;
            list.head = chnge;
            chprev.next = chngr;
		}
		else
		{
            chead.next = chnge;
            chrprev.next = headnxt;
            chprev.next = chngr;
		}
	}

}
