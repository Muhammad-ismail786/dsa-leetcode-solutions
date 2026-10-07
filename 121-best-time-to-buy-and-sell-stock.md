# 121. Best Time to Buy and Sell Stock

## Intuition

Humein stock ko ek din **buy** karna hai aur uske baad kisi later day par **sell** karna hai.

Profit ka formula hai:

`Profit = Selling Price - Buying Price`

Isliye humein har din ke liye ye dekhna hai ke us se pehle sab se **kam price** kya tha.

Hum do cheezein maintain karenge:

* `minPrice` → ab tak ka sab se kam stock price
* `maxProfit` → ab tak ka sab se zyada profit

Example:

`prices = [7,1,5,3,6,4]`

* `7` → minimum price = `7`
* `1` → minimum price update karke `1`
* `5` → profit = `5 - 1 = 4`
* `3` → profit = `3 - 1 = 2`
* `6` → profit = `6 - 1 = 5`
* `4` → profit = `4 - 1 = 3`

Sab se zyada profit `5` hai.

Isliye answer `5` hoga.

## Approach

1. `minPrice` ko first price se initialize karte hain.
2. `maxProfit` ko `0` se initialize karte hain.
3. Array ko second element se last element tak traverse karte hain.
4. Agar current price `minPrice` se chhota hai, to `minPrice` update kar dete hain.
5. Warna current price se `minPrice` subtract karke profit calculate karte hain.
6. Agar current profit `maxProfit` se zyada hai, to `maxProfit` update kar dete hain.
7. End mein `maxProfit` return kar dete hain.

Is tarah humein har possible buy/sell pair ko check karne ki zaroorat nahi padti.

## Complexity

* Time complexity: `O(n)`

Array ko sirf **ek baar** left se right traverse karte hain.

* Space complexity: `O(1)`

Hum sirf kuch variables (`minPrice`, `maxProfit`, `profit`) use kar rahe hain, extra array ya data structure nahi bana rahe.

## Code

```cpp
class Solution {

public:

    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            else {
                int profit = prices[i] - minPrice;

                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
```
