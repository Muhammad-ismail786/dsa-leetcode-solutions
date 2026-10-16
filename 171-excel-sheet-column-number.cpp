class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char letter : columnTitle) {
            result = result * 26;

            int letterValue = letter - 'A' + 1;

            result = result + letterValue;
        }

        return result;
    }
};
