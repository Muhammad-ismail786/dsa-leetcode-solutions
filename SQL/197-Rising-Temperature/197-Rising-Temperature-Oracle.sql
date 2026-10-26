SELECT t1.id
FROM Weather t1
INNER JOIN Weather t2
    ON t1.recordDate = t2.recordDate + 1
WHERE t1.temperature > t2.temperature;
