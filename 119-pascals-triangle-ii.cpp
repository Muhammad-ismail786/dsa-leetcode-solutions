class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = result[j - 1] + result[j];
            }

            result = row;
        }

        return result;
    }
};
