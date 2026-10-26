# 197. Rising Temperature

**# Intuition**

We need to find the IDs of days when the temperature was higher than the previous day. We can use a self-join to compare each day's temperature with the temperature of the previous day.

**# Approach**

1. Use the `Weather` table twice with aliases `t1` and `t2`.
2. Use `DATEDIFF(t1.recordDate, t2.recordDate) = 1` to match each day with the previous day.
3. Use `WHERE t1.temperature > t2.temperature` to select days when the temperature increased.
4. Return the IDs using `SELECT t1.id`.

**# Complexity**

- Time complexity: \(O(n^2)\) — A self-join can compare records across the table; actual performance depends on the database execution plan and indexes.

- Space complexity: \(O(n)\) — Additional space may be needed for join processing, depending on the execution plan.

**# Code**

```mysql
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON DATEDIFF(t1.recordDate, t2.recordDate) = 1
WHERE t1.temperature > t2.temperature;
```
