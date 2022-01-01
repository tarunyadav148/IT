use company;
SELECT Dname,COUNT(*) Number_of_Male_Employee
FROM department,employee
WHERE Dno=Dnumber AND sex='M' AND dname IN (SELECT Dname
                                            FROM department,employee
                                            WHERE Dno=Dnumber
                                            GROUP BY Dname
                                            HAVING AVG(salary)>30000)
GROUP BY Dname;                                            