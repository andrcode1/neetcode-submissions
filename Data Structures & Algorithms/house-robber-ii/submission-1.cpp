class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return std::max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));
    }

private:
    int robHelper(vector<int>& nums, int l, int r) {
        int robPrev = 0;
        int robPrevPrev = 0;

        for (int i = l; i < r; ++i) {
            int temp = std::max(robPrev, robPrevPrev + nums[i]);
            robPrevPrev = robPrev;
            robPrev = temp;
        }

        return std::max(robPrev, robPrevPrev);
    }
};

// 2 9 8 3 6

//
//