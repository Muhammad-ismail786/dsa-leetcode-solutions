# 196. Delete Duplicate Emails

## Problem
Delete duplicate emails from the `Person` table while keeping the row with the smallest `id` for each email.

## Intuition
If multiple rows have the same email, keep the row with the smallest ID and delete the remaining rows.

## Approach
- Compare rows that have the same email.
- Keep the row with the smallest `id`.
- Delete rows with larger IDs for the same email.

## Complexity
- **Time Complexity:** Depends on the database engine and query execution plan.
- **Space Complexity:** Depends on the database engine and execution plan.

## Solutions

- `196-Delete-Duplicate-Emails-MySQL.sql` — MySQL
- `196-Delete-Duplicate-Emails-PostgreSQL.sql` — PostgreSQL
- `196-Delete-Duplicate-Emails-MS-SQL-Server.sql` — MS SQL Server
- `196-Delete-Duplicate-Emails-Oracle.sql` — Oracle
- `196-Delete-Duplicate-Emails-Pandas.py` — Python Pandas
