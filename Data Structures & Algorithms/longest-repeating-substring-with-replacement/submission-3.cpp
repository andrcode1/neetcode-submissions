class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        std::unordered_map<char, int> charFreq;
        int left = 0;
        int right = 1;
        int currentWindow = 2;
        charFreq[s[left]]++;
        charFreq[s[right]]++;
        int maxStreak = 0;

        while (right < s.size()) {
            auto maxFreqPair = std::max_element(charFreq.begin(), charFreq.end(), 
            [](const std::pair<char, int>& a, const std::pair<char, int>& b){
                return a.second < b.second;
            });
            int maxFreq = maxFreqPair->second;

			if ((currentWindow - maxFreq) <= k) {
                maxStreak = std::max(maxStreak, currentWindow);
				right++;
                if (right < s.size()) {
                    charFreq[s[right]]++;
                    currentWindow++;
                }
			} else {
                charFreq[s[left]]--;
                left++;
                currentWindow--;
            }
		}
        maxStreak = std::max(maxStreak, currentWindow);
		return maxStreak;

    }
};
