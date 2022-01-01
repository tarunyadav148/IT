create view Q7_8_c
as select pname, dname, (select count(*)
						from works_on w1
						where w1.pno = p.pnumber) as num_employee,
(select sum(w2.hours)
						from works_on w2
						where w2.pno = p.pnumber 
						group by pno) as total_hours

from project p, department d
   where p.dnum = d.dnumber;
