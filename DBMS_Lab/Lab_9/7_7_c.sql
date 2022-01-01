select fname,lname
from employee
where salary > (select min(salary) from employee)+10000;