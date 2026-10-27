# 202. Happy Number

**Language:** C++

## Intuition
We repeatedly calculate the sum of the squares of each digit.

If the number becomes `1`, it is a Happy Number. If a number repeats before reaching `1`, the process is stuck in a cycle, so we return `false`.

## Approach
1. Create an `unordered_set` named `seen` to store previously visited numbers.
2. Continue while `n` is not equal to `1`.
3. If `n` already exists in `seen`, return `false`.
4. Insert `n` into `seen`.
5. Set `sum = 0`.
6. Extract each digit using `n % 10`.
7. Add the square of each digit to `sum`.
8. Remove the last digit using `n /= 10`.
9. Set `n = sum` and repeat.
10. If `n` reaches `1`, return `true`.

**Example:** `7 → 49 → 97 → 130 → 10 → 1`

## Complexity
- **Time:** `O(log n)` per digit-squaring operation; the overall time depends on the number of distinct values visited.
- **Space:** `O(k)`, where `k` is the number of distinct numbers stored in `seen`.

## Code
```cpp
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.count(n)) {
                return false;
            }

            seen.insert(n);

            int sum = 0;

            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};
```
