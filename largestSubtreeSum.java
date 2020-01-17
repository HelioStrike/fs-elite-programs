/*
Problem: Given a binary tree of 7 nodes, find subtree with maximum sum in tree.


	          1
            /   \
           2      3
          / \    / \
         4   5  6   7
         
Sample Input 1:       
1 2 3 4 5 6 7

Sample Output 1: 
28

Explanation 1:
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.


              1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
 
Sample Input 2:
1 -2 3 4 5 -6 2


Sample Output 2:
7

Explanation 2:
Subtree with largest sum is : -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.

*/

import java.util.Scanner;

class MyBinaryTreeNode { 

	public int data;	
	public MyBinaryTreeNode left;
	public MyBinaryTreeNode right;
	
	public MyBinaryTreeNode(int data){
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

class BinaryTree{
    
	// Root of BinaryTree 
	MyBinaryTreeNode root;
	int ans=-99999999;
	
	public int findLargestSubtreeSum(MyBinaryTreeNode root){
		
		/* write your code here */
		if(root == null) return 0;
		int a = findLargestSubtreeSum(root.left);
		int b = findLargestSubtreeSum(root.right);
		int c = root.data+a+b;
		ans=Math.max(ans,c);
		return c;
	}
	
	
}
public class LargestSubTreeSum {

	
	public static void main(String args[]) 
	{ 
		BinaryTree tree = new BinaryTree(); 
		
		Scanner sc = new Scanner(System.in);
		
		
		//creating a binary tree
		tree.root = new MyBinaryTreeNode(sc.nextInt()); 
		tree.root.setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setRight(new MyBinaryTreeNode(sc.nextInt())); 

        tree.findLargestSubtreeSum(tree.root);
		System.out.println(tree.ans); 

	}
	
}

