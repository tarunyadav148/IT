use company;
SELECT E1.lname,E1.fname
FROM EMPLOYEE E1,EMPLOYEE E2
WHERE E2.Fname='Franklin' AND E2.Lname='Wong' AND E1.superssn=E2.ssn;