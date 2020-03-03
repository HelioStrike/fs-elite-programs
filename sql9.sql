/*

List the Employees number,name,job,hiredate,job,department name of Deptno 20 
whose Jobs are same as Deptno10. order by employee number in ascending


Sample Output :

empno ename job   hiredate    deptno  dname 
7369  SMITH CLERK 1980-12-17     20   RESEARCH


*/

SELECT e.empno, e.ename, e.job, e.hiredate, d.deptno, d.dname FROM emp e
INNER JOIN dept d ON e.deptno=d.deptno WHERE e.job IN (SELECT job FROM emp WHERE deptno=20) AND e.deptno=10;