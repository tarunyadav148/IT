UPDATE EMPLOYEE
SET Salary = 
CASE WHEN Dno = 5 THEN Salary + 2000
 WHEN Dno = 4 THEN Salary + 1500
 WHEN Dno = 1 THEN Salary + 3000
 ELSE Salary + 0 END ;
