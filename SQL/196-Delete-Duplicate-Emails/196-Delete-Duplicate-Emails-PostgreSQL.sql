
DELETE FROM Person t1
USING Person t2
WHERE t1.email = t2.email
  AND t1.id > t2.id;
