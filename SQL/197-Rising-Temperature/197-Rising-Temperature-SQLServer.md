# 197. Rising Temperature — MS SQL Server

**# Intuition**

We need to find the IDs of days when the temperature was higher than the previous day. We can use a self-join to compare the current day's temperature with the previous day's temperature.

**# Approach**

1. Use the `Weather` table twice with aliases `t1` and `t2`.
2. Use `DATEDIFF(DAY, t2.recordDate, t1.recordDate) = 1` to match consecutive days.
3. Use `WHERE t1.temperature > t2.temperature` to find days when the temperature increased.
4. Return the current day's ID using `SELECT t1.id`.

**# Complexity**

- Time complexity: \(O(n^2)\) — A self-join can compare records across the table; actual performance depends on the query plan and indexes.

- Space complexity: \(O(n)\) — Additional space may be required for join processing, depending on the query plan.

**# Code**

```sql
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON DATEDIFF(DAY, t2.recordDate, t1.recordDate) = 1
WHERE t1.temperature > t2.temperature;
```
