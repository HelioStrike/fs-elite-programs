/*
 * 
Given a list of dates, sort them in ascending order, 
Dates are described below

Each date is in the form dd mmm yyyy where 
dd has 0-31
mmm has Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
yyyy is four digits

For Example dates = ['01 Mar 2017','03 Feb 2017','15 Jan 1998'] 
would sort to 
['15 Jan 1998','03 Feb 2017','01 Mar 2017'];

Sample Input
------------
10
20 Oct 2052
06 Jun 1933
26 May 1960
20 Sep 1958
16 Mar 2068
25 May 1912
16 Dec 2018
26 Dec 2061
04 Nov 2030
28 Jul 1963

Sample Output
-------------
25 May 1912
06 Jun 1933
20 Sep 1958
26 May 1960
28 Jul 1963
16 Dec 2018
04 Nov 2030
20 Oct 2052
26 Dec 2061
16 Mar 2068

 * 
 */

import java.util.*;
import java.text.SimpleDateFormat;
public class SortDates {
	public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s;
        ArrayList<Date> arr = new ArrayList();
        SimpleDateFormat format = new SimpleDateFormat("d MMM yyyy");
        for(int i=0;i<n;i++)
        {
            s = sc.nextLine();
            try {
                arr.add(format.parse(s));
            } catch(Exception e) {
                
            }
        }
        Collections.sort(arr);
        for(int i=0;i<n;i++)
        {
            System.out.println(format.format(arr.get(i)));
        }
	}
}