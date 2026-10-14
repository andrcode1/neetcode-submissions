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

//     a b a c d b b a b b
//     0 1 2 3 4 5 6 7 8 9
// dp[i][j] = true -> s[i]..s[j] = palindrome, false - no
// dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] = true)
