#include <bits/stdc++.h>
using namespace std;

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

int main() {

    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words:\n";

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution obj;

    vector<int> result = obj.findSubstring(s, words);

    cout << "Starting indices: ";

    for (int index : result) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
