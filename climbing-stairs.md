# 70. Climbing Stairs

## Intuition

Is problem mein hume stairs ke top tak pohanchna hai.

Har baar hum sirf **1 step** ya **2 steps** climb kar sakte hain.

Agar `n = 3` ho, to 3 ways hain:

```text
1 + 1 + 1
1 + 2
2 + 1
```

Isliye answer `3` hai.

Hum notice karte hain ke har step ka answer previous 2 answers ka sum hota hai:

```text
1 → 1 way
2 → 2 ways
3 → 3 ways
4 → 5 ways
5 → 8 ways
```

Yani:

```text
current = previous + previous_previous
```

Ye **Dynamic Programming** ka simple example hai.

Hume sirf previous 2 values chahiye, isliye hum poora array store nahi karte.

## Approach

Sabse pehle hum 2 starting values set karte hain:

```cpp
prev2 = 1;
prev1 = 2;
```

Ye represent karti hain:

```text
1 step → 1 way
2 steps → 2 ways
```

Phir `3` se `n` tak loop chalayenge.

Har iteration mein:

```cpp
current = prev1 + prev2;
```

Phir values ko update karenge:

```cpp
prev2 = prev1;
prev1 = current;
```

### Example: `n = 5`

Starting:

```text
prev2 = 1
prev1 = 2
```

For `i = 3`:

```text
current = 2 + 1
        = 3
```

For `i = 4`:

```text
current = 3 + 2
        = 5
```

For `i = 5`:

```text
current = 5 + 3
        = 8
```

So final answer:

```text
8
```

## Complexity

* Time complexity: **O(n)**
* Space complexity: **O(1)**

Time `O(n)` hai kyunki loop `3` se `n` tak ek baar chalta hai.

Space `O(1)` hai kyunki hum sirf 3 variables use kar rahe hain:

```text
prev2
prev1
current
```

## Code

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
```
