class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size(), 1000);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }

        return std::min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
