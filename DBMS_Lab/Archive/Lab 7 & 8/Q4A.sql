use company;
SELECT DISTINCT Pnumber
FROM PROJECT
WHERE Pnumber IN (SELECT Pnumber
                  FROM PROJECT,DEPARTMENT,EMPLOYEE
                  WHERE Dnum = Dnumber AND Mgrssn = Ssn AND Lname = 'Smith')
OR Pnumber IN (SELECT Pno
               FROM WORKS_ON,EMPLOYEE
               WHERE Essn = Ssn AND Lname = 'Smith');