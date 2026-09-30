class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right = prices.size() - 1;
        int left = right - 1;
        int maxProfit = 0;
        int currentProfit = 0;

        while (left >= 0) {
            currentProfit = prices[right] - prices[left];
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }

            if (prices[left] > prices[right]) {
                right = left;
            }
            left--;
        }
        return maxProfit;
    }
};
