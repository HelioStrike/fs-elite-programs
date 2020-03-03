/*
List the employees who are senior to most recently hired employee
working under king.

Note : Print results in Order by empno ascending

Use  emp,dept,salgrade tables only 
*/

use demos;

select * from emp where hiredate < (select max(hiredate) from emp where mgr=(select empno from emp where ename='king'));
