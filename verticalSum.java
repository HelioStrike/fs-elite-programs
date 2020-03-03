/*
 * 
write a program to create a binary tree as shown below with 7 nodes and 
to find the vertical sum of the binary tree.

Sample Input:
1 2 3 4 5 6 7

Sample Output:
4 2 12 3 7 

Explanation:
       1
     /   \
   2      3
  / \    / \
 4   5  6   7

The tree has 5 vertical lines
Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7





 * 
 */

import java.util.HashMap;
import java.util.Scanner;
import java.util.*; 


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

	// implemet the following methods
	MyBinaryTreeNode root;
    static TreeMap<Integer,Integer> m = new TreeMap<Integer,Integer>();
    
    static void rec(MyBinaryTreeNode t, int pos)
    {
        if(t==null) return;
        if(m.containsKey(pos)) m.put(pos, m.get(pos)+t.data);
        else m.put(pos, t.data);
        rec(t.left, pos-1);
        rec(t.right, pos+1);
    }
    
    public static void verticalSum(MyBinaryTreeNode root){
        rec(root, 0);
        for(Map.Entry<Integer,Integer> entry : m.entrySet()) {
          int key = entry.getKey();
          int value = entry.getValue();
          System.out.print(value+ " ");
        }
        System.out.println();
    }
	
	
}

public class VerticalSum {
	/* main program */
	public static void main(String args[]) {
		BinaryTree tree = new BinaryTree();

		Scanner sc = new Scanner(System.in);

		MyBinaryTreeNode root = new MyBinaryTreeNode(sc.nextInt()); 
		tree.root = root;
		tree.root.setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getLeft().setRight(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setLeft(new MyBinaryTreeNode(sc.nextInt())); 
		tree.root.getRight().setRight(new MyBinaryTreeNode(sc.nextInt())); 
	        
		tree.verticalSum(tree.root);

	}
}
