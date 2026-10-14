class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 1) {
            return 1;
        }

        int count = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int left = i;
            int right = i;

            while (left >= 0 && right < s.size()) {
                if (s[left] != s[right]) {
                    break; 
                }
                count++;
                left--;
                right++;
            }

            if (i == s.size() - 1) {
                continue;
            }

            left = i;
            right = i+1;

            while (left >= 0 && right < s.size()) {
                if (s[left] != s[right]) {
                    break;
                }
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};

// aabbaa
