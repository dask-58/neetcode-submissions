class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        vector<vector<int>> SUB;
        function<void(int)> backtrack = [&](int k) -> void {
            if (k == n) {
                SUB.push_back(subset);
            } else {
                // exclude k
                backtrack(k + 1);
                // include k
                subset.push_back(nums[k]);
                backtrack(k + 1);
                subset.pop_back(); // backtrack
            }
        };
        backtrack(0);
        return SUB;
    }
};
