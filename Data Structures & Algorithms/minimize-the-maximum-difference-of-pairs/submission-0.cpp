class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n - 1] - nums[0];
        auto ok = [&](int x) -> bool {
            int cnt = 0;
            for (int i = 1; i < n;) {
                if (abs(nums[i] - nums[i - 1]) <= x) {
                    cnt++;
                    i += 2;
                } else {
                    i++;
                }
            }
            return cnt >= p;
        };
        while (l <= r ) {
            int mid = l + (r - l) / 2;
            if (ok(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};