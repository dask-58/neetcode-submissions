class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0, r = 0;
        int n = nums.size();
        deque<int> q; // indices (maintaining decreasing order)
        while (r < n) {
            // pop smaller numbers compared to bigger ones
            while (!q.empty() && nums[q.back()] < nums[r]) q.pop_back();
            q.push_back(r);

            // move window
            if (l > q.front()) q.pop_front();

            // assert size
            if (r + 1 >= k) {
                ans.push_back(nums[q.front()]);
                l++;
            }

            r++;
        }
        return ans;
    }
};
