class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int startIdx = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int left = i;
            int right = i;

            while ((left >= 0 && right < s.size()) && (s[left] == s[right])) {
                if (maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    startIdx = left;
                }
                left--;
                right++;
            }

            if (i == s.size() - 1) {
                break;
            }

            left = i;
            right = i + 1;

            while ((left >= 0 && right < s.size()) && (s[left] == s[right])) {
                if (maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    startIdx = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(startIdx, maxLen);
    }
};
