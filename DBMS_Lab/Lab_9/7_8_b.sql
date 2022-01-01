select e1.fname as 'employee_name',e2.fname as 'supervisor_name',e1.salary as 'employee_salary'
from employee as e1,employee as e2
where e1.superssn = e2.ssn;