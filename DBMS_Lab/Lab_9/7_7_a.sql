select emp.fname,emp.lname
from employee as emp,department as dept
where emp.dno = dept.dnumber and 
dept.dnumber = (select dno from employee where salary = (select max(salary) from employee));