select e.fname, e.lname
from employee as e
where e.ssn in ( select d.essn
from dependent as d
where e.fname = d.dependent_name
and e.sex = d.sex );