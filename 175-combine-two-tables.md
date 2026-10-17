# Intuition

We have two tables: `Person` and `Address`.

The `Person` table contains each person's first name, last name, and person ID. The `Address` table contains the city and state associated with a person ID.

We need to return the first name, last name, city, and state of every person. If a person does not have an address, the city and state should be `NULL`.

We can use `LEFT JOIN` to keep every person in the result, even when no matching address exists.

# Approach

1. Select `firstName` and `lastName` from the `Person` table.
2. Select `city` and `state` from the `Address` table.
3. Use `LEFT JOIN` to combine both tables.
4. Match the tables using `personId`.
5. If no matching address exists, SQL automatically returns `NULL` for the address columns.

# Complexity

- **Time complexity:** `O(P + A)` on average for a hash-based join, where `P` is the number of rows in the `Person` table and `A` is the number of rows in the `Address` table. Actual performance depends on the database execution plan and available indexes.

- **Space complexity:** `O(P + A)` in the worst case for a hash join, due to the temporary hash table. Actual memory usage depends on the execution plan.

# Code

```mysql
SELECT
    p.firstName,
    p.lastName,
    a.city,
    a.state
FROM Person p
LEFT JOIN Address a
    ON p.personId = a.personId;
```
