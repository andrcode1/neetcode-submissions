class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output;
        output.resize(nums.size());

        std::vector<int> productLeftToRight(nums.size());
        productLeftToRight[0] = nums[0];
        std::vector<int> productRightToLeft(nums.size());
        productRightToLeft[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++) {
            productLeftToRight[i] = productLeftToRight[i - 1] * nums[i];
        }

        for (int i = nums.size() - 2; i > 0; i--) {
            productRightToLeft[i] = productRightToLeft[i + 1] * nums[i];
        }

        output[0] = productRightToLeft[1];
        output[nums.size() - 1] = productLeftToRight[nums.size() - 2];

        for (int i = 1; i < nums.size() - 1; i++) {
            output[i] = productRightToLeft[i + 1] * productLeftToRight[i - 1];
        }

        return output;
    }
};
