class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
		    return true;
        }
        std::erase_if(s, [](char c){ return !(std::isalnum(c)); });
        std::transform(s.begin(), s.end(), s.begin(), [](char c) { return std::toupper(c); });
        int i = 0;
        for (auto it = s.rbegin(); it < s.rend(); it++) {
            if (s[i] != *it) {
                return false;
            }
            i++;
            if (i == s.size()/2) {
                return true;
            }
        }
        return true;

    }
};
