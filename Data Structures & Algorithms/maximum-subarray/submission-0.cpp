class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        int sum = ans;
        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};
