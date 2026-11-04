
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if (nums.empty()) {
            return result;
        }

        int start = 0;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != nums[i - 1] + 1) {

                if (start == i - 1) {
                    result.push_back(to_string(nums[start]));
                }
                else {
                    result.push_back(
                        to_string(nums[start]) + "->" +
                        to_string(nums[i - 1])
                    );
                }

                start = i;
            }
        }

        if (start == nums.size() - 1) {
            result.push_back(to_string(nums[start]));
        }
        else {
            result.push_back(
                to_string(nums[start]) + "->" +
                to_string(nums.back())
            );
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 3, 4, 7, 9, 10};

    vector<string> result = obj.summaryRanges(nums);

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";

        if (i < result.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}
