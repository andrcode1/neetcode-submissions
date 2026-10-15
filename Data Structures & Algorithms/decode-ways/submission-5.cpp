class Solution {

public:
    int numDecodings(string s) {
        vector<int> memo(s.size() + 1, 0);
        memo[s.size()] = 1;
        memo[s.size() - 1] = (s[s.size() - 1] == '0') ? 0 : 1;

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '0') {
                memo[i] = 0;
                continue;
            }
            memo[i] += memo[i+1];

            string twoDigits = s.substr(i, 2);
            if (twoDigits >= "10" && twoDigits <= "26") {
                memo[i] += memo[i+2];
            }
        }
        return memo[0];
    }
};


 