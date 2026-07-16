class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < n) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
