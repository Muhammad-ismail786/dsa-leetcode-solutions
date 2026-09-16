# Find the Index of the First Occurrence in a String

## Problem

Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`.

If `needle` is not part of `haystack`, return `-1`.

### Example

```text
Input:
haystack = "sadbutsad"
needle = "sad"

Output:
0
```

---

## Intuition

We need to find where the `needle` string starts inside the `haystack` string.

First, we check every character of `haystack`.

When the current character matches the first character of `needle`, we consider it a possible starting position.

Then, we compare all characters of `needle` with the corresponding characters of `haystack`.

If all characters match, we return the starting index.

If no complete match is found, we return `-1`.

---

## Approach

1. Initialize `result = -1`.
2. Use an outer `for` loop to go through every character of `haystack`.
3. Check whether `haystack[i]` matches the first character of `needle`.
4. If it matches, store `i` as the possible starting index.
5. Use an inner `for` loop to compare the characters of `needle` with `haystack`.
6. Increase `count` whenever the characters match.
7. If `count == needle.size()`, the complete `needle` has been found.
8. Return the starting index.
9. If no match is found, return `-1`.

---

## Code

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;

        for(int i = 0; i < haystack.size(); i++) {

            if(haystack[i] == needle[0]) {

                result = i;
                int count = 0;

                if(i + needle.size() <= haystack.size()) {

                    for(int j = 0; j < needle.size(); j++) {

                        if(haystack[i + j] == needle[j]) {
                            count++;
                        }
                    }

                    if(count == needle.size()) {
                        return result;
                    }
                }
            }
        }

        return -1;
    }
};
```

---

## Dry Run

### Input

```text
haystack = "sadbutsad"
needle = "sad"
```

### Step 1

```text
i = 0

haystack[0] = 's'
needle[0]   = 's'
```

Both characters match.

So:

```text
result = 0
```

### Step 2

Now compare the complete `needle`:

```text
haystack[0] = 's'  → needle[0] = 's'  ✅
haystack[1] = 'a'  → needle[1] = 'a'  ✅
haystack[2] = 'd'  → needle[2] = 'd'  ✅
```

Therefore:

```text
count = 3
needle.size() = 3
```

So:

```text
count == needle.size()
```

The complete string is found.

Return:

```text
0
```

---

## Complexity

### Time Complexity

\(O(n \times m)\)

Where:

* `n` = length of `haystack`
* `m` = length of `needle`

We may check the characters of `needle` at every possible position in `haystack`.

### Space Complexity

\(O(1)\)

We only use a few variables such as `i`, `j`, `result`, and `count`.

---

## Key Concepts

* String Traversal
* Nested `for` Loops
* Character Comparison
* Indexing
* Two-Level Searching
* Time and Space Complexity
