use company;
CREATE VIEW EnameSnameEsalary (employee_name,supervisor_name,employee_salary)
AS SELECT E1.Fname,E2.Fname,E1.Salary
   FROM employee E1,employee E2
   WHERE E1.superssn=E2.ssn;