# 182. Duplicate Emails

## Intuition

We need to find all email addresses that appear more than once in the `Person` table.

If an email appears multiple times, it is a duplicate email. We can use `GROUP BY` to group the same email addresses together and `COUNT(*)` to count how many times each email appears.

## Approach

1. Use `FROM Person` to get data from the `Person` table.
2. Use `GROUP BY email` to group rows with the same email address.
3. Use `COUNT(*) > 1` to identify email groups that appear more than once.
4. Use `HAVING` to filter the groups and return only duplicate emails.
5. Use `AS Email` to name the result column `Email`.

## Complexity

- Time complexity: \(O(n)\) average, assuming hash-based grouping. With sorting-based grouping, it can be \(O(n \log n)\).

- Space complexity: \(O(n)\) in the worst case, where \(n\) is the number of rows, because the database may need to store groups during processing.

## Code

```mysql
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;
```
