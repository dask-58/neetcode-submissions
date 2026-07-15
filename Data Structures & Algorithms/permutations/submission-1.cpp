class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> PERM;
        sort(nums.begin(), nums.end());
        do {
            PERM.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return PERM;
    }
};
