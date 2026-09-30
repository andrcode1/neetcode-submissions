class Solution {
public:
    void incrementCount(auto& charCounts, char charToInsert) {
        auto search = charCounts.find(charToInsert);
        if (search != charCounts.end()) {
            search->second++;
        } else {
            charCounts.insert({charToInsert, 1});
        }
    }

    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> charCounts1;
        std::unordered_map<char, int> charCounts2;
        if (s.length() != t.length()) {
            return false;
        }
        
        for (int i = 0; i < s.length(); i++) {
            incrementCount(charCounts1, s.at(i));
            incrementCount(charCounts2, t.at(i));
        }
        if (charCounts1 != charCounts2) {
            return false;
        }
        return true;
    }
};
