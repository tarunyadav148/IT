select dept.dname,count(*) as "No. of employee whose salary > 30000"
from employee as emp,department as dept
where emp.dno = dept.dnumber
group by dept.dnumber having avg(emp.salary)>30000;

