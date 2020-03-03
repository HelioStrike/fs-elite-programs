/*
 * 
 * 
 * 
 * 
 * 

 Write a Program to print all the combinations of  well-formed braces form the given no of
 pairs of braces.
 
 Note: Print List in Sorted Order(Ascending)
 
 input :2
Output: [{{}},{}{}]


 */



import java.util.*;

public class ProduceBraces {

        static int n;
        static ArrayList<String> ans = new ArrayList<String>();

	    static void generateBraces(String cur, int curl,int curp) {
	      // write your code here
	      if(curl==n)
	      {
	          if(curp==0) ans.add(cur);
	          return;
	      }
	      generateBraces(cur+"{",curl+1,curp+1);
	      if(curp>0) generateBraces(cur+"}",curl+1,curp-1);
	    }

	    
	    public static void main(String args[] ) {
			 Scanner sc = new Scanner(System.in);
				n=Integer.parseInt(sc.next())*2;
                generateBraces("", 0, 0);
			    System.out.println(ans);
		}
	
}