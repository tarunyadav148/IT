select dno, count(*)
from employee
where salary>40000 and dno in
( select dno
from employee
group by dno
having count(*) > 5)
group by dno;