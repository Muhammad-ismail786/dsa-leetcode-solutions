
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            if(mp.count(n)) {
                int distance = abs(i - mp[n]);

                if(distance <= k) {
                    return true;
                }
            }

            mp[n] = i;
        }

        return false;
    }
};
