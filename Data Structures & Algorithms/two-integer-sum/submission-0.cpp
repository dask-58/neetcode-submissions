class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans.push_back(mp[complement]);
                ans.push_back(i);
            } else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};
