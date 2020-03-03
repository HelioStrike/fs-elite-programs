/*
Display the names of employees from department number 10 with salary
greater than that of any employee working in other departments.

Note: use emp,dept,salgrade tables
*/
use demos;

select ename from emp where deptno=10 and sal>(select min(sal) from emp where deptno!=10);