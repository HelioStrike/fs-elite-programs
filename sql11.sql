/*

Display the grade, number of employees, max salary and avg salary of each
grade. order by grade ascending


Note : round avg to 2 decimal places

Sample Output :

grade   employees   maxsal      avgsal 
1            3      1100.00     950.00

*/

SELECT grade, COUNT(*) AS employees, ROUND(MAX(sal),2) AS maxsal, ROUND(AVG(sal),2) AS avgsal
FROM emp e INNER JOIN salgrade s ON e.sal BETWEEN s.losal AND s.hisal GROUP BY grade;