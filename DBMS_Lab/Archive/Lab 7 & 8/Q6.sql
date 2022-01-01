use company;
SELECT Fname,Lname
FROM EMPLOYEE
WHERE NOT EXISTS (SELECT *
                  FROM DEPENDENT
                  WHERE Ssn = Essn);