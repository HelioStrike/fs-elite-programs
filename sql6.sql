/*
List the employees who are senior to their own manager



Sample Output :

empno 	ename 	mgr 	hiredate 	mgrempo 	mgrename 	mgrhiredate 	
7369 	SMITH 	7902 	1980-12-17 	7902 		FORD 		1981-12-03

Note : Order by empno(ascending)

*/

SELECT e.empno AS empno, e.ename AS ename, e.mgr AS mgr,
e.hiredate AS hiredate, m.empno AS mgrempo, m.ename AS mgrename, m.hiredate AS mgrhiredate
FROM emp e, emp m WHERE e.mgr=m.empno AND e.hiredate<m.hiredate ORDER BY empno;