
# 37. Sudoku Solver

**Difficulty:** Hard

**LeetCode:** https://leetcode.com/problems/sudoku-solver/

## Intuition

We need to fill all empty cells ('.') in a 9x9 Sudoku board while following three rules:

- Each number from 1 to 9 must appear exactly once in every row.
- Each number from 1 to 9 must appear exactly once in every column.
- Each number from 1 to 9 must appear exactly once in every 3x3 box.

We can use Backtracking to try different numbers until we find a valid solution.

## Approach

1. Traverse the entire board using two nested loops.
2. Find an empty cell represented by '.'.
3. Try numbers from '1' to '9'.
4. Check whether the number already exists in the current row, column, or 3x3 box.
5. If the number is valid, place it in the empty cell.
6. Recursively solve the remaining Sudoku.
7. If recursion returns true, the Sudoku is solved, so return true.
8. If the number does not lead to a solution, reset the cell to '.' and try another number. This process is called Backtracking.
9. If no empty cells remain, return true because the Sudoku is solved.

## Complexity

- Time complexity: O(9^m), where m is the number of empty cells (upper bound).
- Space complexity: O(m), where m is the number of empty cells due to the recursion stack.

## Code

```cpp
class Solution {
public:

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char num = '1'; num <= '9'; num++) {

                        bool valid = true;

                        for (int i = 0; i < 9; i++) {

                            if (board[row][i] == num ||
                                board[i][col] == num) {

                                valid = false;
                                break;
                            }

                            int r = 3 * (row / 3) + i / 3;
                            int c = 3 * (col / 3) + i % 3;

                            if (board[r][c] == num) {
                                valid = false;
                                break;
                            }
                        }

                        if (valid) {

                            board[row][col] = num;

                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
```
