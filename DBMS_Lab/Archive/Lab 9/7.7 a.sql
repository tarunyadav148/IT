use company;
SELECT fname,lname
FROM employee
WHERE Dno=(SELECT Dno
           FROM employee
           WHERE Salary=(SELECT MAX(Salary)
                         FROM employee));