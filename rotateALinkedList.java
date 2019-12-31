
import java.util.Scanner;

/*
 * Problem: Rotate singly linked list by k-places to the right .
 * 
 
Sample Input 1: 
10 20 30 40 50 60 -1
4

Sample Output 1: 
Given Linked List                                                                                                       
10 20 30 40 50 60                                                                                                       
Linked List after Rotation                                                                                              
30 40 50 60 10 20
    

Sample Input 2: 
10 20 30 40 50 60 -1
5

Sample Output 2: 
Given Linked List                                                                                                       
10 20 30 40 50 60                                                                                                       
Linked List after Rotation                                                                                              
60 10 20 30 40 50

 * 
 * 
 */
 
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

	// Return a string representation of this collection, in the form
	// "str1" "str2" ....
	public String toString() {
		String result = "";
		if (head == null) {
			return "NULL";
		}
		result = result + head.getData();
		MyListNode temp = head.getNext();
		while (temp != null) {
			result = result + " " + temp.getData();
			temp = temp.getNext();
		}
		
		return result;
	}

	// Return the current length of the list.
	public int length() {
		return length;
	}

}
public class RotateLinkedList {
	
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
			
			int k=sc.nextInt();

			System.out.println("Given Linked List");
			System.out.println(list.toString());

			// call reverse list iterative function
			list.head = rotateRight(list.head,k);
			System.out.println("Linked List after Rotation");
			System.out.println(list.toString());

		}
		

	 
    public static MyListNode rotateRight1(MyListNode head, int n) {
        /*
            Write Your Code Here
        */
        for(int i=0;i<n; i++)
        {
            MyListNode first = head;
            MyListNode cur = first;
            int curdata = -1,tmp;
            while(cur!=null)
            {
                tmp = cur.data;
                cur.data = curdata;
                curdata = tmp;
                cur = cur.next;
            }
            first.data = curdata;
        }
        return head;
    }
    
    public static MyListNode rotateRight(MyListNode head, int n) {
        /*
            Write Your Code Here
        */
        MyListNode cur = head;
        int len = 0;
        while(cur!=null)
        {
            len++; cur=cur.next;
        }
        n%=len;
        cur=head;
        MyListNode prev=head,nh=null;
        int rem=len-n;
        while(cur!=null)
        {
            rem--;
            prev=cur;
            cur=cur.next;
            if(rem==0) { prev.next=null; nh=cur; }
        }
        prev.next = head;
        return nh;
    }
}