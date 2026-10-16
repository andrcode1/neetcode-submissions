class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> wordsInDict;
        for (auto& word : wordDict) {
            wordsInDict.insert(word);
        }

        std::vector<bool> dp (s.size(), false);
        std::vector<int> prevIdxAfterTrue;
        prevIdxAfterTrue.push_back(0);

        for (int i = 0; i < s.size(); ++i) {
            bool isWord = false;
            for (int idx : prevIdxAfterTrue) {
                if (wordsInDict.contains(s.substr(idx, i - idx + 1))) {
                    isWord = true;
                }
            }
            if (wordsInDict.contains(s.substr(i, 1))) {
                isWord = true;
            }
            dp[i] = isWord;

            if (i == 0) {
                continue;
            }
            
            if (dp[i-1]) {
                prevIdxAfterTrue.push_back(i);
            }
        }

        return dp[s.size() - 1];
    }
};
