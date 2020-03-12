/*
 * 
 Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input:1 2 0
Output: 3
Example 2:

Input: 3 4 -1 1
Output: 2
Example 3:

Input: 7 8 9 11 12
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.


 */



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Missing {

	public static int firstMissingPositive(int[] nums) {
        int temp = 0;
        for(int i=0;i<nums.length;i++)
        {
            while(nums[i]>0 && nums[i]<i+1)
            {
                int k=nums[i]-1;
                temp = nums[k];
                nums[k] = nums[i];
                nums[i] = temp;
            }
        }
        int j=0;
        for(;j<nums.length;j++)
        {
            if(nums[j]!=j+1) break;
        }
        return j+1;
    }
	
	public static void main(String args[] ) throws IOException {

	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		String[] numberline = str.split(" ");
		int[] nums = Arrays.asList(numberline).stream().mapToInt(Integer::parseInt).toArray();

		System.out.println(firstMissingPositive(nums));   
		
		}
}