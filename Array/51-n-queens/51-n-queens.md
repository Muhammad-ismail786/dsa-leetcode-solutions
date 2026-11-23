# LeetCode 51 - N-Queens (C++)

## # Intuition

The idea is to place `n` queens on an `n x n` chessboard so that no two queens can attack each other.

A queen can attack horizontally, vertically, and diagonally. Therefore, every queen must be placed in a safe position.

We place one queen in each row and try different columns until we find all valid board configurations.

## # Approach

We use **Backtracking** to solve this problem.

1. Create an `n x n` chessboard filled with `.` (empty cells).
2. Start placing queens from the first row.
3. Use the `isSafe()` function to check whether a queen can be placed in a particular column.
4. Check the upper column, upper-left diagonal, and upper-right diagonal.
5. If the position is safe, place the queen (`Q`) and move to the next row.
6. If all queens are placed successfully, save the current board in the answer.
7. Remove the queen (`.`) and try another column. This process is called backtracking.
8. Return all valid board configurations.

## # Complexity

- **Time complexity:** `O(N! × N)` — We explore possible queen placements and check whether each position is safe.

- **Space complexity:** `O(N²)` — To store the chessboard and recursion-related space, excluding the output.

## # Code

```cpp
class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check upper column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<string>& board, int row, int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                backtrack(board, row + 1, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0, n);

        return ans;
    }
};
```
