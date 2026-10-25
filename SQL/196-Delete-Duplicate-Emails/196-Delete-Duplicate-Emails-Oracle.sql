
DELETE FROM Person t1
WHERE EXISTS (
    SELECT 1
    FROM Person t2
    WHERE t1.email = t2.email
      AND t1.id > t2.id
);
