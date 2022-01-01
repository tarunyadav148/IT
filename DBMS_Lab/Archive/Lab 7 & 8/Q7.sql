use company;
SELECT Fname,Lname
FROM EMPLOYEE
WHERE EXISTS (SELECT *
              FROM DEPENDENT
              WHERE Ssn = Essn)
AND EXISTS (SELECT *
            FROM DEPARTMENT
            WHERE Ssn = Mgrssn);