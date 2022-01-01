use company;
SELECT DISTINCT Essn
FROM WORKS_ON
WHERE (Pno,Hours) IN (SELECT Pno,Hours
                      FROM WORKS_ON
                      WHERE Essn = '123456789');