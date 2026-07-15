class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            score += abs(s[i - 1] - s[i]);
        }
        return score;
    }
};