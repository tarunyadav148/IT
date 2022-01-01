use company;
CREATE VIEW PnameDnameNoOfEmployeesTotalHours(ProjectName,DepartmentName,NoOfEmployees,HoursWorkedPerWeek) AS
SELECT P.Pname,D.Dname,COUNT(*),AVG(Salary)
FROM employee E,department D,works_on W,project P
WHERE E.Dno=D.Dnumber AND W.Pno=P.Pnumber AND W.Essn=E.Ssn AND P.Dnum=D.Dnumber
GROUP BY P.Pname;