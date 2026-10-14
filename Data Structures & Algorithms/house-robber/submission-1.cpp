class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);

        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i-1], nums[i] + dp[i-2]);
        }

        return std::max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};

// 2 9 8   3   6
// 2 9 10      

//     1, 10, 8,  9,  10
// dp: 1, 10, 10, 19, 20       
// dp[i] = the max value we can steal up until i-th house
// dp[i] = dp[i] + std::max(dp[i-2], dp[i-3])

// 2 10 9 1 8
// a: 2, 9, 8
