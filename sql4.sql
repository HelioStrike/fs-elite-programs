/*
Write a Query in MySQL to find out least 5 earners of the company.

NOTE: use emp, dept,  salgrade tables.
*/
use demos;

SELECT * FROM emp e WHERE (SELECT COUNT(DISTINCT sal) FROM emp WHERE sal < e.sal) < 5 ORDER BY ename;