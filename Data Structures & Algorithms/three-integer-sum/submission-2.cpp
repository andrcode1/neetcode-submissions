class Solution {
public:

    int advanceLeftToRight(vector<int>& nums, int left) {
	left++;
	while (left < nums.size() and nums[left] == nums[left-1]) {
		left++;
	}
	return left;
    }

    int advanceRightToLeft(vector<int>& nums, int right) {
        right--;
        while (right > 0 and nums[right] == nums[right+1]) {
            right--;
        }
        return right;
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }
            int target = 0 - nums[i];
            int it_left = i + 1;
            int it_right = nums.size() - 1;
            while (it_left < it_right) {
                if(nums[it_left] + nums[it_right] == target) {
                    result.push_back({nums[i], nums[it_left], nums[it_right]});
                    it_left = advanceLeftToRight(nums, it_left);
                    it_right = advanceRightToLeft(nums, it_right);

                } else if(nums[it_left] + nums[it_right] < target) {
                    it_left = advanceLeftToRight(nums, it_left);

                } else if(nums[it_left] + nums[it_right] > target) {
                    it_right = advanceRightToLeft(nums, it_right);
                }
            }
        }
        return result;

        }
};
