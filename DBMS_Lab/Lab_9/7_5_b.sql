select dept.dname,count(*) as "No. of male employee whose salary > 30000"
from employee as emp,department as dept
where emp.dno = dept.dnumber and emp.sex='M'
group by dept.dnumber having avg(emp.salary)>30000;