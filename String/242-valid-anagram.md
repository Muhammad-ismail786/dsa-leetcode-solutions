
# 242. Valid Anagram

## Intuition

The main idea is to check whether both strings contain the same characters with the same frequency.

- If the lengths of both strings are different, return false.
- Create an array of size 26 to store character frequencies.
- Increase the frequency of each character in string `s`.
- Decrease the frequency of each character in string `t`.
- If any character's frequency becomes negative, return false.
- Otherwise, return true.

## Approach

1. First, check whether the lengths of both strings are equal.
2. Create an integer array `count[26]` initialized with zeros.
3. Traverse string `s` and increase the frequency of each character using `count[ch - 'a']++`.
4. Traverse string `t` and decrease the frequency of each character using `count[ch - 'a']--`.
5. If any frequency becomes negative, return false.
6. If all characters are processed successfully, return true.

## Complexity

- Time complexity: O(n)

  We traverse both strings once, where n is the length of the strings.

- Space complexity: O(1)

  We use a fixed-size array of 26 elements.

## Code

```cpp
#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length()) {
        return false;
    }

    int count[26] = {0};

    for (char ch : s) {
        count[ch - 'a']++;
    }

    for (char ch : t) {
        count[ch - 'a']--;

        if (count[ch - 'a'] < 0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "Output: true" << endl;
    }
    else {
        cout << "Output: false" << endl;
    }

    return 0;
}
```
