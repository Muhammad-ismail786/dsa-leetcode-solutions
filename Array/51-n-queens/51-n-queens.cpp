
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

int main() {

    Solution solution;

    int n;

    cout << "Enter board size: ";
    cin >> n;

    vector<vector<string>> result = solution.solveNQueens(n);

    cout << "\nTotal Solutions: " << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {

        cout << "\nSolution " << i + 1 << ":\n";

        for (string row : result[i]) {
            cout << row << endl;
        }
    }

    return 0;
}
