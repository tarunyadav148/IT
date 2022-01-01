USE company;
CREATE VIEW MyView3 AS
SELECT dname,dependent_name,fname,pname
FROM department,dependent,employee,project
WHERE pname = 'LaserPrinters';