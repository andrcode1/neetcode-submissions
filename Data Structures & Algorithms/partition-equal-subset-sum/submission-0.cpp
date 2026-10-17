class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumArray = std::accumulate(nums.begin(), nums.end(), 0);
        if (sumArray % 2 != 0) {
            return false;
        }
        int target = sumArray / 2;

        std::vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};

