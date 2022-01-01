use company;
SELECT Lname,Fname
FROM EMPLOYEE
WHERE NOT EXISTS (SELECT *
                  FROM WORKS_ON B
                  WHERE (B.Pno IN (SELECT Pnumber
                                   FROM PROJECT
                                   WHERE Dnum = 5)
                  AND
                  NOT EXISTS (SELECT *
                              FROM WORKS_ON C
                              WHERE C.Essn = Ssn
                              AND C.Pno = B.Pno)));