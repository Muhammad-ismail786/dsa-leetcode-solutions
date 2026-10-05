# Pascal's Triangle — Iterative Row Construction

## Intuition

Pascal's Triangle is built row by row.

Each row starts and ends with `1`. The numbers in between are calculated by adding the two adjacent numbers from the previous row.

For example:

```text
Previous row:  1  3  3  1
Next row:      1  4  6  4  1
```

Here:

* `3 + 1 = 4`
* `3 + 3 = 6`
* `3 + 1 = 4`

## Approach

* Create a 2D vector `result` to store all rows.
* Use a `for` loop to generate each row.
* The current row contains `i + 1` elements.
* Initialize every element of the row with `1`.
* The first and last elements remain `1`.
* Calculate the middle elements using the previous row.
* Add the current row to `result`.
* Return the complete Pascal's Triangle.

## Complexity

* Time complexity: **O(n²)**
* Space complexity: **O(n²)**

The output itself contains `O(n²)` elements, so storing the Pascal's Triangle requires `O(n²)` space.

## Code

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};
```
