
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Check if the partition is correct
            if (l1 <= r2 && l2 <= r1) {

                // If total elements are even
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                // If total elements are odd
                return max(l1, l2);
            }

            // Move left if first array's left value is too large
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // Otherwise, move right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {

    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double result = solution.findMedianSortedArrays(nums1, nums2);

    cout << "Median: " << result << endl;

    return 0;
}
