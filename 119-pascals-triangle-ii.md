# Pascal's Triangle II

## Intuition

Pascal's Triangle mein har row ka pehla aur last element `1` hota hai. Beech ke elements previous row ke do adjacent elements ko add karke bante hain.

Hum `result` mein previous row store karenge aur har iteration mein new row banayenge. Jab `rowIndex` tak pohanch jayenge, `result` mein required row hogi.

## Approach

1. `result` ko empty vector se start karte hain.
2. `i = 0` se `rowIndex` tak loop chalate hain.
3. Har iteration mein `i + 1` elements ki row banate hain, aur initially sab ko `1` rakhte hain.
4. Inner loop se middle elements calculate karte hain:
   `row[j] = result[j - 1] + result[j]`
5. New row ko `result` mein store kar dete hain.
6. End mein `result` return kar dete hain.

## Complexity

* **Time complexity:** `O(n²)`
* **Space complexity:** `O(n)`

## Code

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = result[j - 1] + result[j];
            }

            result = row;
        }

        return result;
    }
};
```
