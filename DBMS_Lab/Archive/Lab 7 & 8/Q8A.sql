use company;
SELECT E.Lname AS Employee_name, S.Lname AS Supervisor_name
FROM EMPLOYEE AS E,EMPLOYEE AS S
WHERE E.Superssn = S.Ssn;