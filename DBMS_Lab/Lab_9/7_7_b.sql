select fname,lname
from employee
where superssn in (select ssn from employee where superssn='888665555');