/*
 * Problem:(Problem No.32 from Linked List) 
 * Given two sorted Linked Lists, we need to merge them into the third list in sorted order.
 * 
 * 
	Sample Input : 
    10 20 30 40 50 -1
	15 25 35 45 -1

	Sample Output : 
	10 15 20 25 30 35 40 45 50
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
	public void setdata(int elem) {
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



	// Return the current length of the list.
	public int length() {
		return length;
	}

}

public class MergeSortedLists {
	
	
	// static ListNode head;
		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
			int tempData = -1;

			// create a linked list
			MyLinkedList list1 = new MyLinkedList();

			// add nodes one by one till you find end of the character
			while ((tempData = sc.nextInt()) != -1) {
				// add nodes to the linked list
				list1.insertAtEnd(new MyListNode(tempData));
			}
			
			// create a linked list
			MyLinkedList list2 = new MyLinkedList();

			// add nodes one by one till you find end of the character
			while ((tempData = sc.nextInt()) != -1) {
				// add nodes to the linked list
				list2.insertAtEnd(new MyListNode(tempData));
			}

			// create a linked list
			MyLinkedList mergedList = new MyLinkedList();

			// call merge two lists iterative function
			mergedList.head = mergeTwoLists(list1.head,list2.head);
			
            while(mergedList.head != null)
            {
                System.out.print(mergedList.head.data+" ");
                mergedList.head = mergedList.head.next;
            }
            System.out.println();
		}
	
	
	public static MyListNode mergeTwoLists(MyListNode head1, MyListNode head2) {
       // write your code here
       MyListNode head = new MyListNode(-1);
       MyListNode cur = head, prev = null;
       while(head1 != null && head2 != null)
       {
           if(head1.data < head2.data) { cur.data = head1.data; head1 = head1.next; }
           else { cur.data = head2.data; head2 = head2.next; }
           cur.next = new MyListNode(-1);
           prev = cur;
           cur = cur.next;
       }
       while(head1 != null)
       {
           cur.data = head1.data;
           head1 = head1.next;
           prev = cur;
           cur = cur.next;
       }
       while(head2 != null)
       {
           cur.data = head2.data;
           head2 = head2.next;
           prev = cur;
           cur = cur.next;
       }
       prev.next = null;
       return head;
    }
}
