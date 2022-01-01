use company;
CREATE VIEW ManagerInfo
AS SELECT Dname,Fname,Lname,Salary
   FROM department,employee
   WHERE mgrssn=ssn;