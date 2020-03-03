/*
Display the list of strings with length is <=k using stream api.
Print largest odd number in the given array of elements using stream api.
Print all statistics(Max,Min,Sum,Avg) using Statistics Collectors on a given list.

Input Format
------------
First line of the input contains 2 integers N, K. 
N is the number of strings. K is the length of the word.
Next N lines are strings
Next list of numbers. List size is <=20

Output Format
-------------
Print list of strings with length is <=K 
Print largest odd number in the given array
Next Four Lines of output follows
Maximum number of list,
Minimum number of list,
Sum of list,
Average of list(Average Value - Round up to 2 decimal places)


Sample Input
4 5
Elite
Finishing School
SONET
Trishul
10 17 21 5 44

Sample Output
Elite SONET 
21
44
5
97
19.4


*/

import java.util.*;
import java.util.stream.*;

class StreamExercise {
	public static void main(String args[]) {
        //write your code here
        int n,m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        ArrayList<String> sarr = new ArrayList<String>();
        for(int i=0;i<n;i++)
        {
            sarr.add(sc.nextLine());
        }
        sarr.stream().filter(x -> x.length() <= m).forEach(x -> System.out.print(x+" "));
        System.out.println();
        List<Integer> iarr = new ArrayList<Integer>(Arrays.asList(sc.nextLine().split(" ")).stream().map(x -> Integer.parseInt(x)).collect(Collectors.toList()));
        System.out.println(iarr.stream().filter(x -> x%2 == 1).reduce(-1, (ans, i) -> Math.max(ans, i)));
        System.out.println(iarr.stream().reduce(-1, (ans, i) -> Math.max(ans, i)));
        System.out.println(iarr.stream().reduce(9999999, (ans, i) -> Math.min(ans, i)));
        System.out.println(iarr.stream().reduce(0, (ans, i) -> ans+i));
        System.out.println(iarr.stream().reduce(0, (ans, i) -> ans+i)*1.0/iarr.size());
	}
}
