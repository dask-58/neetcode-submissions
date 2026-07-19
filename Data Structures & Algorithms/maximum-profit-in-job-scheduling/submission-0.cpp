class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> intervals;
        for (int i = 0; i < n; i++) intervals.push_back({startTime[i], endTime[i], profit[i]});
        sort(intervals.begin(), intervals.end());

        vector<int> memo(n, -1);
        auto dfs = [&](auto&& self, int i) -> int {
            if (i == n) return 0;
            if (memo[i] != -1) return memo[i];

            int skip = self(self, i + 1);

            int end = intervals[i][1];
            int pro = intervals[i][2];

            int idx = lower_bound(intervals.begin(), intervals.end(), array<int, 3>{end, 0, 0}) - intervals.begin();

            int take = pro + self(self, idx);

            return memo[i] = max(skip, take);
        };

        return dfs(dfs, 0);
    }
};