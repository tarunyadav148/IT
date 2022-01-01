SELECT E.Fname,E.Lname,E.Address
FROM EMPLOYEE AS E,DEPARTMENT AS D
WHERE D.Dname='Research' AND D.Dnumber=E.Dno;