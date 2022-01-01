use company;
SELECT fname,lname
FROM employee
WHERE superssn IN (SELECT ssn 
                   FROM employee
                   WHERE superssn='888665555');