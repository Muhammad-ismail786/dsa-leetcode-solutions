# 190. Reverse Bits

## Intuition
We are given a 32-bit integer. Our task is to reverse the order of its 32 binary bits and return the resulting number.

## Approach
1. Convert the given number into a 32-bit binary string using `bitset<32>`.
2. Reverse the binary string using the `reverse()` function.
3. Convert the reversed binary string into an unsigned decimal number using `stoul()` with base `2`.
4. Return the resulting number as an integer.

## Complexity
- Time complexity: $$O(1)$$ — The number always contains exactly 32 bits, so the amount of work is fixed.
- Space complexity: $$O(1)$$ — The binary string always has a fixed length of 32 characters.

## Code
```cpp
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        string binaryStr = bitset<32>(n).to_string();

        reverse(binaryStr.begin(), binaryStr.end());

        unsigned int reversed_decimal = stoul(binaryStr, nullptr, 2);

        return static_cast<int>(reversed_decimal);
    }
};
```
