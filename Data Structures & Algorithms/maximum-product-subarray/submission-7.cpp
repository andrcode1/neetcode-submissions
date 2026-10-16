class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            int temp = num * currMax;
            currMax = std::max(std::max(num, temp), num * currMin);
            currMin = std::min(std::min(num, temp), num * currMin);
            maxProduct = std::max(maxProduct, currMax);
        }

        return maxProduct;
    }
};
