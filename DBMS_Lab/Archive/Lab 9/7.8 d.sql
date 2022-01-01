use company;
CREATE VIEW PnameDnameNoOfEmployeesTotalHours_v2 AS
SELECT Pname,Dname,(SELECT COUNT(*)
                    FROM works_on W1
                    WHERE W1.Pno=P.Pnumber) AS NumberOfEmployee,(SELECT SUM(W2.Hours)
                                                                 FROM works_on W2
                                                                 WHERE W2.Pno=P.Pnumber
                                                                 GROUP BY Pno) AS TotalHours
FROM project P,department D
WHERE P.Dnum=D.Dnumber AND (SELECT COUNT(*) 
							FROM works_on W2
                            WHERE W2.Pno=P.Pnumber
                            GROUP BY W2.Pno)>1;                                                                 