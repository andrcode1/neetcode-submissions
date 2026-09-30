class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> uniqueNums;
	for (int n : nums) {
		uniqueNums.insert(n);
	}

	int maxStreak = 0;
	int currentStreak = 0;

	for (int& n : nums) {
		if (uniqueNums.empty()) {
			break;
		}
		if (!uniqueNums.contains(n)) {
			continue;
		}
		currentStreak++;
		uniqueNums.erase(n);

		int n_temp = n;
		while (uniqueNums.contains(n_temp + 1)) {
			currentStreak++;
			uniqueNums.erase(n_temp);
			n_temp++;
		}
		n_temp = n;
		while (uniqueNums.contains(n_temp - 1)) {
			currentStreak++;
			uniqueNums.erase(n_temp);
			n_temp--;
		}
		maxStreak = std::max(maxStreak, currentStreak);
		currentStreak = 0;
	}
	return maxStreak;

    }
};
