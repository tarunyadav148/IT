create view Q7_8_d
as select pname, dname, (select count(*)
						from works_on w1
						where w1.pno = p1.pnumber) as num_employee, 
(select sum(w2.hours)
						from works_on w2
						where w2.pno = p1.pnumber 
						group by pno) as total_hours
from project p1, department d1
   where p1.dnum = d1.dnumber and (select count(*)
								  from works_on w2
								  where w2.pno = p1.pnumber
								  group by w2.pno) > 1;
