Select emp.Fname, emp.Lname
from employee as emp, works_on as w, project as p
where emp.Dno = 5 and emp.ssn = w.Essn and w.Pno = p.pnumber and p.pname = 'ProductX' and w.hours > 10;