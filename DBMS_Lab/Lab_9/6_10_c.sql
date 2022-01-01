select fname,lname
from employee
where superssn = (select ssn from employee where fname='Franklin' and lname='Wong');