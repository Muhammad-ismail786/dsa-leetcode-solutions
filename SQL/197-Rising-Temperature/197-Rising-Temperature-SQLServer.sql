
-- Write your MS SQL Server query statement below
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON DATEDIFF(DAY, t2.recordDate, t1.recordDate) = 1
WHERE t1.temperature > t2.temperature;
