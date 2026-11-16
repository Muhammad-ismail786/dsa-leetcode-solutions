# 30. Substring with Concatenation of All Words

**LeetCode Problem:** [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

## # Intuition

We need to find all starting indices where the substring contains every word from the `words` array exactly once, in any order.

Since all words have the same length, we can use a Sliding Window and an `unordered_map` to count words efficiently.

## # Approach

1. First, calculate the length of each word and the total number of words.
2. Create an `unordered_map` to store how many times each word appears in the `words` array.
3. Try different starting positions from `0` to `wordLength - 1`.
4. Use two pointers, `left` and `right`, to maintain a sliding window.
5. Extract a word of `wordLength` from the current `right` position.
6. If the extracted word does not exist in `wordCount`, clear the `seen` map and reset the window.
7. If the word exists, increase its count in `seen`.
8. If a word appears more times than allowed, move the `left` pointer forward and remove extra words.
9. When the window contains all required words, add the `left` index to the answer.
10. Finally, return the answer vector.

## # Complexity

- **Time complexity:** \(O(n \times m)\)

  Where `n` is the length of string `s` and `m` is the length of each word. This accounts for extracting substrings and hash map operations.

- **Space complexity:** \(O(k \times m)\)

  Where `k` is the number of unique words stored in the hash maps and `m` is the word length.

## # Code

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (words.empty()) {
            return ans;
        }

        int wordLength = words[0].length();
        int totalWords = words.size();

        if (s.length() < wordLength * totalWords) {
            return ans;
        }

        unordered_map<string, int> wordCount;

        // Step 1: Count words
        for (string word : words) {
            wordCount[word]++;
        }

        // Step 2: Try different starting positions
        for (int i = 0; i < wordLength; i++) {

            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            // Step 3: Move through string
            for (int right = i;
                 right + wordLength <= s.length();
                 right += wordLength) {

                string word = s.substr(right, wordLength);

                // Step 4: Check if word exists
                if (wordCount.find(word) == wordCount.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLength;
                    continue;
                }

                seen[word]++;
                count++;

                // Step 5: Remove extra words
                while (seen[word] > wordCount[word]) {

                    string leftWord = s.substr(left, wordLength);

                    seen[leftWord]--;
                    count--;

                    left += wordLength;
                }

                // Step 6: All words found
                if (count == totalWords) {

                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLength);

                    seen[leftWord]--;
                    count--;

                    left += wordLength;
                }
            }
        }

        return ans;
    }
};
```
