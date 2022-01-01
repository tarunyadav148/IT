create view Q7_8_a as
select dept.dname as 'Department name',concat(emp.fname," ",emp.lname) as 'Manager name',emp.salary as 'Manager salary'
from department as dept,employee as emp
where dept.dnumber=emp.dno;