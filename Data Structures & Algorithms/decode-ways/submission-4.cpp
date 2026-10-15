class Solution {

public:
    int numDecodings(string s) {
        vector<int> memo(s.size() + 1, 0);
        memo[s.size()] = 1;
        initializeMemo(memo, s);

        for (int i = s.size() - 3; i >= 0; --i) {
            if (s[i] == '0') {
                memo[i] = 0;
                continue;
            }
            memo[i] += memo[i+1];

            string twoDigits = s.substr(i, 2);
            if (twoDigits == "10") {
                memo[i] = memo[i+2];
            }
            if (twoDigits >= "11" && twoDigits <= "26") {
                memo[i] += memo[i+2];
            }
        }
        return memo[0];
    }
private:
    void initializeMemo(vector<int>& memo, string& s) {
        int last = s.size() - 1;
        int beforeLast = s.size() - 2;
        
        memo[last] = (s[last] == '0') ? 0 : 1;
        if (beforeLast == -1) {
            return;
        }

        if (s[beforeLast] == '0') {
            memo[beforeLast] = 0;
            return;
        }
        memo[beforeLast] += memo[last];

        string twoDigits = s.substr(beforeLast, 2);
        if (twoDigits >= "10" && twoDigits <= "26") {
            memo[beforeLast] += 1;
        }
    }   
};


 