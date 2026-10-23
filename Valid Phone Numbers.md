# Intuition
We need to print only valid phone numbers from `file.txt`. A valid phone number must match one of two formats: `xxx-xxx-xxxx` or `(xxx) xxx-xxxx`.

# Approach
Use the `grep -E` command with a regular expression (Regex) to match either valid format. The `^` and `$` symbols ensure that the entire line matches the required format.

# Complexity
- Time complexity: \(O(n)\), where n is the total number of characters in the file.
- Space complexity: \(O(1)\) auxiliary space, excluding internal implementation details of `grep`.

# Code
```bash
# Read from the file file.txt and output all valid phone numbers to stdout.
grep -E '^([0-9]{3}-[0-9]{3}-[0-9]{4}|\([0-9]{3}\) [0-9]{3}-[0-9]{4})$' file.txt
```
