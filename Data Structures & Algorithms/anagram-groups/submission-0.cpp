class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> sortedStrings;
        for (string s : strs) {
            string sortedString = s;
            std::sort(sortedString.begin(), sortedString.end());
            sortedStrings[sortedString].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& s : sortedStrings) {
            res.push_back(s.second);
        }
        return res;
    }
};
