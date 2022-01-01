use company;
SELECT Fname,Lname
FROM employee,dependent
WHERE ssn=essn AND Fname=dependent_name;