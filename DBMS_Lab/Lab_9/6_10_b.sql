select emp.fname,emp.lname
from employee as emp, dependent as dep
where emp.ssn = dep.essn and emp.fname = dep.dependent_name;