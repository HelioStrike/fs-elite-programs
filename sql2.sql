/* 
Display names of the employee(s) earning the highest grade 3 salary and working in
CHICAGO
Note : Display only name in ascending order

Use  emp,dept,salgrade tables only 

*/

select ename from emp where deptno=(select deptno from dept where loc='CHICAGO')
and sal=(select max(sal) from emp where
    sal >= (select losal from salgrade where grade=3)
    and sal <= (select hisal from salgrade where grade=3)
) order by ename asc;