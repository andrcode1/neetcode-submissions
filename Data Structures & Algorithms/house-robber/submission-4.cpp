class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (int n : nums) {
            int temp = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
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
