use company;
SELECT Lname,Fname
FROM EMPLOYEE
WHERE (SELECT COUNT(*)
       FROM DEPENDENT
       WHERE Ssn = Essn) >= 2;