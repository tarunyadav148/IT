use company;
SELECT Dname, COUNT(*) Number_of_Employee
FROM department,employee
WHERE Dno=Dnumber
GROUP BY Dname
HAVING AVG(Salary)>30000;