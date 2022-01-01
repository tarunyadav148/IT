use company;
SELECT fname,lname
FROM employee
WHERE salary>=10000+(SELECT MIN(salary)
				     FROM employee);