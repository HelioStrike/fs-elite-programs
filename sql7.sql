/*
Find all the names and salary of the employees who earn the minimum Salary for each job wise in ascending
order of their sal.

*/

SELECT ename, sal FROM emp e WHERE sal = (SELECT MIN(sal) FROM emp WHERE job = e.job) ORDER BY sal;