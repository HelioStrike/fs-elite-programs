/*

List the manager names who are senior to KING and who are junior to
SMITH
Note : names in ascending order

*/

SELECT ename FROM emp WHERE hiredate < (SELECT hiredate FROM emp WHERE ename = 'KING')
AND hiredate > (SELECT hiredate FROM emp WHERE ename = 'SMITH')
AND empno IN (SELECT mgr FROM emp) ORDER BY ename;