class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int start = goal - 1; start >= 0; --start) {
            if (start + nums[start] >= goal) {
                goal = start;
            }
        }

        return goal == 0;
    }
};
