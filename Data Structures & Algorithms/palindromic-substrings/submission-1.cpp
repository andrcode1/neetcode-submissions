class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        if (s.size() == 1) {
            return 1;
        }

        int count = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i;  j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i + 1 <= 3 || dp[i+1][j-1])) {
                    count++;
                    dp[i][j] = 1;
                }
            }
        }
        return count;
    }
};
