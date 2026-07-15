class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int twosteps = (i + 2 <= n ? dp[i + 2] : 0);
            dp[i] = min(dp[i + 1], twosteps) + cost[i];
        }
        return min(dp[0], dp[1]);
    }
};
