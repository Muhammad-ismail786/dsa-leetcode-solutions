# Intuition

The first thought was to treat the first string as a base and compare each of its characters with the same position in every other string. As soon as a mismatch is found, that marks the end of the common prefix.

# Approach

Loop through each character (index i) of the first string (strs[0]). For each character, compare it with the character at the same position (i) in every other string (index j).

If any string is too short or the character doesn't match, immediately return the substring of strs[0] from index 0 to i.

If the loop completes without any mismatch, the entire first string is the common prefix.

# Complexity

- Time Complexity: O(n × m)
- Space Complexity: O(1)
