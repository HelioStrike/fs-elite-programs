
/*
Given a Binary Tree, print left view of it. 
Left view of a Binary Tree is set of nodes visible 
when tree is visited from left side.

Note: -1 represents "no node"

Sample Input :     
11
1 2 3 4 5 -1 6 -1 8 9 10

Sample Output : 
1 2 4 8

Explanation: 
	    1
	  /   \
	 2     3
	/ \     \
	4  5    6
	\ / \
	8 9 10
          
 * 
 */

import java.util.Scanner;

//MyBinaryTreeNode Class containing left and right child of current node and data value
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


	void leftView(MyBinaryTreeNode root) {

		/* write your code here */
        if(root==null) return;
        System.out.println(root.data);
        if(root.left==null) leftView(root.right);
        else leftView(root.left);
	}

}

public class LeftViewOfBinaryTree {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int numOfNodes = sc.nextInt();
		BinaryTree bt = new BinaryTree();
		int arr[] = new int[numOfNodes];
		for (int i = 0; i < numOfNodes; i++)
			arr[i] = sc.nextInt();
		bt.root = new MyBinaryTreeNode(arr[0]);
		bt.root = bt.insertLevelOrder(arr, bt.root, 0);
		bt.leftView(bt.root);

	}

}
