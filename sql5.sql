/*

List the enames who are retiring after 1989-12-31 the max Job period is 20 Years,
in ascending order.

Note: use emp, dept, salgrade

*/
use demos;

SELECT ename FROM emp WHERE hiredate > DATE_ADD('1989-12-31', INTERVAL -20 YEAR) ORDER BY ename;
