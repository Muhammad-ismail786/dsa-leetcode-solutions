# 197. Rising Temperature — Oracle

**# Intuition**

Humein un dinon ki IDs find karni hain jin ka temperature pichlay din se zyada tha.

**# Approach**

1. `Weather` table ko do baar use karte hain: `t1` current day ke liye aur `t2` previous day ke liye.
2. `t1.recordDate = t2.recordDate + 1` se consecutive days match karte hain.
3. `WHERE t1.temperature > t2.temperature` se temperature increase check karte hain.
4. `SELECT t1.id` se current day ki ID return karte hain.

**# Complexity**

- Time complexity: \(O(n^2)\) — self-join ki wajah se, actual performance query plan aur indexes par depend karti hai.
- Space complexity: \(O(n)\) — join process ke liye extra space lag sakti hai.

**# Code**

```sql
SELECT t1.id
FROM Weather t1
INNER JOIN Weather t2
    ON t1.recordDate = t2.recordDate + 1
WHERE t1.temperature > t2.temperature;
```
