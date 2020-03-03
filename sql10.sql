/*
List the  employee name,Job,Salary,hiredate,Dept Location of employees who are belonging 
DALLAS or CHICAGO with
the grade same as ADAMS or experience more than SMITH.

Note : Names in Ascending Order

Sample Output :

ename   job     sal     hiredate        loc                                                                             
FORD    ANALYST 6000.00 1981-12-03      DALLAS
*/

/* Code by Sidharth *.

select e1.ename,e1.job,e1.sal,e1.hiredate,d1.loc from emp e1 inner join dept d1  using(deptno) 
inner join salgrade sg on e1.sal between losal and hisal
where (loc ='DALLAS' or loc='CHICAGO' ) and (e1.hiredate<(select hiredate from emp where ename='SMITH') or 
sg.grade=(select grade from emp inner join salgrade on emp.sal between losal and hisal where ename='ADAMS')) 
and (e1.ename!="ADAMS") and e1.ename!="SMITH"
order by e1.ename;