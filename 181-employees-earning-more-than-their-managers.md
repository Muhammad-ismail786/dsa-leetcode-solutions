
# 181. Employees Earning More Than Their Managers

## Intuition

We need to find employees who earn more than their managers.

The `Employee` table contains the employee's ID, name, salary, and manager's ID.

An employee's `managerId` matches the `id` of their manager in the same table. Therefore, we can use a Self Join to compare an employee's salary with their manager's salary.

## Approach

1. Use the `Employee` table twice with different aliases:
   - `t1` represents the employee.
   - `t2` represents the manager.
2. Use `INNER JOIN` to match each employee with their manager.
3. Match `t1.managerId` with `t2.id`.
4. Use the `WHERE` clause to select employees whose salaries are greater than their managers' salaries.
5. Use `AS Employee` to rename the output column to the required name.

## Code

```sql
SELECT t1.name AS Employee
FROM Employee AS t1
INNER JOIN Employee AS t2
    ON t1.managerId = t2.id
WHERE t1.salary > t2.salary;
```

## Example

### Input

| id | name | salary | managerId |
|---:|---|---:|---:|
| 1 | Joe | 70000 | 3 |
| 2 | Henry | 80000 | 4 |
| 3 | Sam | 60000 | NULL |
| 4 | Max | 90000 | NULL |

### Output

| Employee |
|---|
| Joe |

### Explanation

- Joe earns 70000, while his manager Sam earns 60000. Joe is included in the result.
- Henry earns 80000, while his manager Max earns 90000. Henry is excluded.
- Sam and Max have no manager ID, so they do not match a manager record.

Therefore, Joe is the only employee who earns more than their manager.

## Complexity

- **Time Complexity:** Depends on the database execution plan and indexes. Without efficient indexing, a join can require quadratic work in the worst case.
- **Space Complexity:** Depends on the execution plan and intermediate join results.

## Important Concepts

- **Self Join:** Joining a table with itself to compare related records.
- **INNER JOIN:** Returns records that have matching records on both sides of the join.
- **Alias:** A temporary name given to a table or column.
- **ON:** Specifies the condition used to match records.
- **WHERE:** Filters records according to a condition.
- **AS:** Assigns an alias to a column or table.

## Interview Notes

A Self Join is useful when related records exist in the same table. Here, `t1` represents an employee and `t2` represents their manager. We match `t1.managerId` with `t2.id`, then compare their salaries to return employees who earn more than their managers.
