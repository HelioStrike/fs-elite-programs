
import java.util.*;
/*
Problem: Given a Binary Tree having positive and negative nodes, 
the task is to find maximum sum level in it.

		              4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6

Sample Input :
7
4 2 -5 -1 3 -2 6

Output: 
6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

*/

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
    int arr[] = new int[50];

	// Function to insert nodes in level order
	public MyBinaryTreeNode insertLevelOrder(int[] arr, MyBinaryTreeNode root, int i) {
		// Base case for recursion
		if (i < arr.length) {
			MyBinaryTreeNode temp = new MyBinaryTreeNode(arr[i]);
			root = temp;

			// insert left child
			root.left = insertLevelOrder(arr, root.left, 2 * i + 1);

			// insert right child
			root.right = insertLevelOrder(arr, root.right, 2 * i + 2);
		}
		return root;
	}

	public int maxSumInBinaryTreeLevel(MyBinaryTreeNode root, int depth) {

        if(root==null) return depth;
        arr[depth]+=root.data;
        int a=maxSumInBinaryTreeLevel(root.left,depth+1);
        int b=maxSumInBinaryTreeLevel(root.right,depth+1);
        return Math.max(a,b);
	}

}

public class MaxInBinaryTreeLevelSum {

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);

		int numOfNodes = sc.nextInt();
		BinaryTree bt = new BinaryTree();
		int arr[] = new int[numOfNodes];
		for (int i = 0; i < numOfNodes; i++)
			arr[i] = sc.nextInt();
		bt.root = new MyBinaryTreeNode(arr[0]);
		bt.root = bt.insertLevelOrder(arr, bt.root, 0);
        int depth=bt.maxSumInBinaryTreeLevel(bt.root,0);
        int ans=0;
        for(int i=0;i<depth;i++) ans=Math.max(ans,bt.arr[i]);
        System.out.println(ans);
	}

}