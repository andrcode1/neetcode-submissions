class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxLen = 0;
        int startIdx = 0;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i + 1 <= 3 || dp[i+1][j-1])) {
                    dp[i][j] = true;

                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};

//     a b a c d b b a b b
//     0 1 2 3 4 5 6 7 8 9
// dp[i][j] = true -> s[i]..s[j] = palindrome, false - no
// dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] = true)
