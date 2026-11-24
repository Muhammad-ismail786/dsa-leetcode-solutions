
# 52. N-Queens II

**Difficulty:** Hard

**Topic:** Backtracking, Recursion

**Language:** C++

## # Intuition

The main idea is to place `n` queens on an `n x n` chessboard so that no two queens attack each other.

We place one queen in each row and check whether its column and both diagonals are already occupied.

If a safe position is found, we place the queen and move to the next row using recursion.

Whenever all `n` rows have a queen, we increase the count by 1.

## # Approach

1. Create three boolean arrays:
   - `cols` to track occupied columns.
   - `diag1` to track occupied diagonals using `row - col + n - 1`.
   - `diag2` to track occupied diagonals using `row + col`.

2. Start placing queens from row 0.

3. Check every column to find a safe position.

4. If the position is safe:
   - Mark the column and both diagonals as occupied.
   - Recursively move to the next row.
   - Backtrack by marking them as unoccupied.

5. If `row == n`, all queens are successfully placed, so increment `count`.

6. Finally, return the total count.

## # Complexity

- Time complexity: O(N!) approximately, due to backtracking and trying different queen placements.

- Space complexity: O(N) auxiliary space for the columns and diagonal tracking arrays.

## # Code

```cpp
class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<bool>& cols,
               vector<bool>& diag1, vector<bool>& diag2) {

        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {

            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n, cols, diag1, diag2);

            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, cols, diag1, diag2);

        return count;
    }
};
```

## # Example

**Input:**
```text
n = 4
```

**Output:**
```text
2
```

**Explanation:**

There are two distinct ways to place four queens on a 4 x 4 chessboard so that no two queens attack each other.

## # Tags

- Backtracking
- Recursion
- Array
- LeetCode
