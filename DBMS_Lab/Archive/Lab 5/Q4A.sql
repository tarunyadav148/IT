use company;
( SELECT DISTINCT Pnumber
 FROM PROJECT, DEPARTMENT, EMPLOYEE
 WHERE Dnum = Dnumber AND mgrssn = Ssn
 AND Lname = 'Smith' )
 UNION
( SELECT DISTINCT Pnumber
 FROM PROJECT, WORKS_ON, EMPLOYEE
 WHERE Pnumber = Pno AND Essn = Ssn
 AND Lname = 'Smith' );