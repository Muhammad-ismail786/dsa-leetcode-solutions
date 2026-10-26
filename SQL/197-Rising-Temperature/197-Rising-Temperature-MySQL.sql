
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON DATEDIFF(t1.recordDate, t2.recordDate) = 1
WHERE t1.temperature > t2.temperature;
