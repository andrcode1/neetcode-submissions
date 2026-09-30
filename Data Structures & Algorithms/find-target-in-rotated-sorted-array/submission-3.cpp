class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int targetIndex = -1;

        if (nums.size() == 1 and nums[0] == target) {
            targetIndex = 0;
        }

        while (left < right) {
            int middle = (left + right) / 2;

            if (nums[middle] == target) {
                targetIndex = middle;
                break;
            }

            if (nums[left] == target) {
                targetIndex = left;
                break;
            }

            if (nums[right] == target) {
                targetIndex = right;
                break;
            }

            if (nums[middle] <= nums[right]) {
                if (target > nums[middle] and target < nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else if (nums[left] <= nums[middle]) {
                if (target > nums[left] and target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }

        return targetIndex;
    }
};
