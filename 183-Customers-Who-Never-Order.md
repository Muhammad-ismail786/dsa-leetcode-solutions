# 183. Customers Who Never Order

## Intuition
We need to find customers who have never placed an order. We can use a `LEFT JOIN` to include all customers and identify those who do not have a matching record in the `Orders` table.

## Approach
1. Use `LEFT JOIN` to combine the `Customers` and `Orders` tables.
2. Match customers using `Customers.id = Orders.customerId`.
3. Use `WHERE t2.customerId IS NULL` to select only customers who have never placed an order.
4. Return their names using the `Customers` column alias.

## Complexity
- Time complexity: \(O(n + m)\) — where `n` is the number of customers and `m` is the number of orders, assuming efficient join processing.
- Space complexity: \(O(n + m)\) — in the worst case, depending on the database's join execution strategy and temporary storage.

## Code
```mysql
SELECT t1.name AS Customers
FROM Customers AS t1
LEFT JOIN Orders AS t2
ON t1.id = t2.customerId
WHERE t2.customerId IS NULL;
```
