class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> wordSet;
        int maxLen = 0;
        for (auto& word : wordDict) {
            wordSet.insert(word);
            maxLen = std::max(maxLen, static_cast<int>(word.size()));
        }

        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= i - maxLen + 1; --j) {
                if (j >= 0 && dp[j] && wordSet.contains(s.substr(j, i - j + 1))) {
                    dp[i+1] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
