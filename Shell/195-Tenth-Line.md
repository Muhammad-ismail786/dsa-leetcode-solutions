# 195. Tenth Line

**Difficulty:** Easy

**Language:** Bash

**LeetCode:** [195. Tenth Line](https://leetcode.com/problems/tenth-line/)

## Intuition

We need to print only the 10th line from a text file named `file.txt`.

Instead of reading and printing every line manually, we can use the `sed` command to select and print the required line.

## Approach

1. Use the `sed` command to process the text file.
2. Use `-n` to prevent `sed` from printing every line automatically.
3. Use `10p` to print only the 10th line.
4. Specify `file.txt` as the input file.
5. If the file contains fewer than 10 lines, the command prints nothing.

## Complexity

- **Time Complexity:** \(O(n)\) — In the worst case, the command may read the entire file. Here, \(n\) represents the number of lines in the file.
- **Space Complexity:** \(O(1)\) — The command uses a constant amount of extra memory for this operation.

## Code

```bash
# Read from the file file.txt and output the tenth line to stdout.
sed -n '10p' file.txt
```

## Explanation

- `sed`: A command-line tool used to process text.
- `-n`: Prevents automatic printing of every line.
- `'10p'`: Prints only line number 10.
- `file.txt`: The input text file.

## Example

**Input (`file.txt`):**

```text
Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
```

**Output:**

```text
Line 10
```

## Important Note

If `file.txt` contains fewer than 10 lines, `sed -n '10p' file.txt` produces no output.

LeetCode provides `file.txt` when evaluating this problem. You do not need to create or upload the input file separately on LeetCode.

## Key Takeaway

The command `sed -n '10p' file.txt` prints only the 10th line of a text file.
