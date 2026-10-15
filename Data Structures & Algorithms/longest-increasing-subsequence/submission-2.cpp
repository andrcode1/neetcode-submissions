class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxPath = 1;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] > nums[i]) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                    maxPath = std::max(maxPath, dp[j]);
                }
            }
        }

        return maxPath;
    }
};

//    1 100 2 3 4
// dp 1  2  2 3 4
