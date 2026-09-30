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

        std::string answerString = "";
        std::string currentString = "";

        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (charCapacity[s[i]] != 0) {
                left = i;
                charCapacity[s[i]]--;
                currentString += s[i];
                break;
            }
        }

        if (currentString == t) {
            return currentString;
        }

        for (int right = left + 1; right < s.size(); right++) {
            currentString += s[right];
            if (charCapacity.contains(s[right])) {
                charCapacity[s[right]]--;
            }

            if (!foundValidSubstring(charCapacity)) {
                continue;
            }

            if (currentString.size() < answerString.size() or answerString.empty()) {
                answerString = currentString;
            }

            while (foundValidSubstring(charCapacity)) {
                if (charCapacity.contains(s[left])) {
                    charCapacity[s[left]]++;
                }
                currentString.erase(0,1);
                left++;

                if (foundValidSubstring(charCapacity)) {
                    if (currentString.size() < answerString.size()) {
                        answerString = currentString;
                    }
                }
            }
        }

        return answerString;
    }
};
