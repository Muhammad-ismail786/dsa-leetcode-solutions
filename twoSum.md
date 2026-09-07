// LeetCode 1: Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int required = target - current;
            if (map.find(required) != map.end()) {
                return { map[required], i };
            }
            map[current] = i;   
        }
        return {};   
    }
};
