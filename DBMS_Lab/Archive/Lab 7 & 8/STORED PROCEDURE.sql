use mydb;
DELIMITER &&
CREATE PROCEDURE func3()
BEGIN
     SELECT * FROM DEPENDENT WHERE sex = 'M';
END &&

CALL func3();