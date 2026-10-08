# 125. Valid Palindrome

## Intuition

The main idea is to first create a clean version of the string.

We:
- Ignore spaces and special characters.
- Convert uppercase letters to lowercase.
- Store only letters and numbers in a new string.
- Reverse the cleaned string.
- Compare the cleaned string with its reversed version.

If both strings are the same, the original string is a palindrome.

## Approach

1. Create an empty string `clean`.
2. Traverse the original string character by character.
3. Check if the current character is a letter or number using `isalnum()`.
4. Convert the character to lowercase using `tolower()`.
5. Add the lowercase character to `clean`.
6. Create another string called `reversed` and copy `clean` into it.
7. Reverse `reversed`.
8. Compare `clean` and `reversed`.
9. If they are equal, return `true`; otherwise, return `false`.

## Complexity

- Time complexity: O(n)

The string is traversed once to create `clean`, and then the cleaned string is reversed and compared.

- Space complexity: O(n)

We use extra strings `clean` and `reversed` to store the characters.

## Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string clean;

        for(int i = 0; i < s.size(); i++) {

            if(isalnum(s[i])) {

                char lower_case = tolower(s[i]);
                clean += lower_case;

            }
        }

        string reversed;
        reversed = clean;

        reverse(reversed.begin(), reversed.end());

        if(clean == reversed) {
            return true;
        }
        else {
            return false;
        }
    }
};
