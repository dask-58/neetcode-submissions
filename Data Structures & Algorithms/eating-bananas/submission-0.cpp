class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        auto ok = [&](int x) -> bool {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (piles[i] + x - 1) / x;
            }
            return cnt <= h;
        };

        int ans = -1;
        while (l <= r) {
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
