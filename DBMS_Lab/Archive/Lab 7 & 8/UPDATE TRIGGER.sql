use mydb;
DELIMITER &&
CREATE TRIGGER MyTrigger
BEFORE UPDATE ON employee FOR EACH ROW
BEGIN
IF NEW.working_hours < 0 THEN SET NEW.working_hours = 0;
END IF;
END &&