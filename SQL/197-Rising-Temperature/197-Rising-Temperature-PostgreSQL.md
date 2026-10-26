# 197. Rising Temperature — PostgreSQL

**# Intuition**

We need to find the IDs of days when the temperature was higher than the previous day. We can join the Weather table with itself to compare temperatures between consecutive days.

**# Approach**

1. Use a self-join on the `Weather` table.
2. Use `INTERVAL '1 day'` to match each date with the previous day.
3. Filter rows where the current day's temperature is higher than the previous day's temperature.
4. Return the current day's `id`.

**# Complexity**

- Time complexity: \(O(n^2)\) — A self-join can compare records across the table; actual performance depends on the query plan and indexes.

- Space complexity: \(O(n)\) — Additional space may be used for join processing, depending on the query plan.

**# Code**

```sql
SELECT t1.id
FROM Weather AS t1
INNER JOIN Weather AS t2
    ON t1.recordDate = t2.recordDate + INTERVAL '1 day'
WHERE t1.temperature > t2.temperature;
```
