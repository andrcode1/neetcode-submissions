class Solution {
   public:

    bool foundValidSubstring(std::unordered_map<char, int>& charCapacity) {
        bool foundValidSubstring = true;
            for (auto it = charCapacity.begin(); it != charCapacity.end(); it++) {
                if (charCapacity[it->first] > 0) {
                    foundValidSubstring = false;
                    break;
                }
            }
        return foundValidSubstring;
    }

    string minWindow(string s, string t) {
        std::unordered_map<char, int> charCapacity;
        for (char c : t) {
            charCapacity[c]++;
        }

        int startIdx = 0;
        int minLength = INT_MAX;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charCapacity.contains(s[right])) {
                charCapacity[s[right]]--;
            }

            if (!foundValidSubstring(charCapacity)) {
                continue;
            }

            if ((right - left + 1) < minLength) {
                startIdx = left;
                minLength = right - left + 1;
            }

            while (foundValidSubstring(charCapacity)) {
                if ((right - left + 1) < minLength) {
                    startIdx = left;
                    minLength = right - left + 1;
                }

                if (charCapacity.contains(s[left])) {
                    charCapacity[s[left]]++;
                }
                left++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(startIdx, minLength);
    }
};
