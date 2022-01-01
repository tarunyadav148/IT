use company;
SELECT Fname,Lname
FROM employee,works_on,project
WHERE Dno=5 AND ssn=essn AND pno=pnumber AND pname='ProductX' AND hours>10;