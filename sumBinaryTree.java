/*
 * 
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf 
 * path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:
Sample input: 5 4 8 11 13 4 7 2 -1 -1 -1 1
22

output :
true

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1


return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class TreeNode {

	public int data;
	public TreeNode left;
	public TreeNode right;

	public TreeNode(int data) {
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

	public TreeNode getLeft() {
		return left;
	}

	public void setLeft(TreeNode left) {
		this.left = left;
	}

	public TreeNode getRight() {
		return right;
	}

	public void setRight(TreeNode right) {
		this.right = right;
	}

}


class BinaryTree {

	// Root of BinaryTree
	TreeNode root;

	// Function to insert nodes in level order
	public TreeNode insertLevelOrder(int[] arr, TreeNode root, int i) {
		// Base case for recursion
		if (i < arr.length) {
			TreeNode temp = new TreeNode(arr[i]);
			root = temp;
			if (arr[i] == -1)
				return null;

			// insert left child
			root.left = insertLevelOrder(arr, root.left, 2 * i + 1);

			// insert right child
			root.right = insertLevelOrder(arr, root.right, 2 * i + 2);
		}
		return root;
	}

	/* Has Path Sum */
	public boolean hasPathSum(TreeNode root, int sum) {
	    if(root == null && sum == 0) return true;
	    if(root == null) return false;
	    return hasPathSum(root.left,sum-root.data) || hasPathSum(root.right, sum-root.data);
	    // Write your code here
	   
	  }
	
	
		  
}




public class SumBinaryTree {

	public static void main(String args[] ) throws IOException {

	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    BinaryTree bt=new BinaryTree();
		
		String str = br.readLine();
		String[] numbers = str.split(" ");
		int[] arr = Arrays.asList(numbers).stream().mapToInt(Integer::parseInt).toArray();

		bt.root = new TreeNode(arr[0]);
		bt.root = bt.insertLevelOrder(arr, bt.root, 0);
		int sum=Integer.parseInt(br.readLine());
		System.out.println(bt.hasPathSum(bt.root,sum));
		}
	
	  
}


