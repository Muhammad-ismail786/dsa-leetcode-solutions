
-- Write your PostgreSQL query statement below
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON t1.recordDate = t2.recordDate + INTERVAL '1 day'
WHERE t1.temperature > t2.temperature;
