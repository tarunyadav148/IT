SELECT E.Fname, E.Lname
FROM EMPLOYEE AS E
WHERE E.Ssn IN ( SELECT D.Essn
 FROM DEPENDENT AS D
 WHERE E.Fname = D.Dependent_name
 AND E.Sex = D.Sex );