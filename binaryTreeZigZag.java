
import java.util.*;

/*
Problem: Write a program to display Zigzag order traversal of a given n nodes tree.

		       	  1
		       /	 \  
		      /       \
		     /   	   \
		    2      	    3
		  /   \    	  /   \
		 4     5  	 6     7
	    / \   / \   / \   / \
       8  9  10 11  12 13 14 15
 
Sample Input:15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

Sample Output:
1 3 2 4 5 6 7 15 14 13 12 11 10 9 8

*/
// MyBinaryTreeNode Class containing left and right child of current node and data value
class MyBinaryTreeNode {

	public int data;
	public MyBinaryTreeNode left;
	public MyBinaryTreeNode right;

	public MyBinaryTreeNode(int data) {
		this.data = data;
		left = null;
		right = null;
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public MyBinaryTreeNode getLeft() {
		return left;
	}

	public void setLeft(MyBinaryTreeNode left) {
		this.left = left;
	}

	public MyBinaryTreeNode getRight() {
		return right;
	}

	public void setRight(MyBinaryTreeNode right) {
		this.right = right;
	}

}

class BinaryTree {

	// Root of BinaryTree
	MyBinaryTreeNode root;

	
		// Function to insert nodes in level order
		public MyBinaryTreeNode insertLevelOrder(int[] arr, MyBinaryTreeNode root, int i) {

			// Base case for recursion
			if (i < arr.length) {

				if (arr[i] == -1)
					return null;

				MyBinaryTreeNode temp = new MyBinaryTreeNode(arr[i]);
				root = temp;

				// insert left child
				root.left = insertLevelOrder(arr, root.left, 2 * i + 1);

				// insert right child
				root.right = insertLevelOrder(arr, root.right, 2 * i + 2);

			}
			return root;
		}

		
		
	public void zigzagTreeOrder(MyBinaryTreeNode root) {
        // write your code here
	}

}// end of BinaryTree

public class BinaryTreeZigzagTraversals {

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);

		int numOfNodes = sc.nextInt();
		BinaryTree bt = new BinaryTree();
		int arr[] = new int[numOfNodes];
		for (int i = 0; i < numOfNodes; i++)
			arr[i] = sc.nextInt();
		bt.root = new MyBinaryTreeNode(arr[0]);
		bt.root = bt.insertLevelOrder(arr, bt.root, 0);
		bt.zigzagTreeOrder(bt.root);

	}

}
