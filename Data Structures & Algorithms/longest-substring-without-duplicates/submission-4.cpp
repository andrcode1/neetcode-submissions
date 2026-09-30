class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        std::unordered_set<char> seenCharacters;
        int longestSubstring = 0;
        int currentSubstring = 0;

        int left = 0;
        int right = 1;
        seenCharacters.insert(s[left]);
        currentSubstring++;
        
        while (right < s.size()) {
            if (!seenCharacters.contains(s[right])) {
                currentSubstring++;
                seenCharacters.insert(s[right]);
                right++;
            } else if (seenCharacters.contains(s[right])) {
                if (currentSubstring > longestSubstring) {
                    longestSubstring = currentSubstring;
                }
                while (s[left] != s[right]) {
                    seenCharacters.erase(s[left]);
                    left++;
                }
                seenCharacters.erase(s[left]);
                left++;
                currentSubstring = right - left;
            }
        }

        if (currentSubstring > longestSubstring) {
            return currentSubstring;
        }
        return longestSubstring;
    }
};
