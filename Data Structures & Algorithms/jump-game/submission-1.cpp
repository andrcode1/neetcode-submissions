class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> canReach(nums.size(), false);
        canReach[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (!canReach[i]) {
                continue;
            }

            for (int jump = i + 1; jump <= i + nums[i]; ++jump) {
                canReach[jump] = true;
            }
        }

        return canReach.back();
    }
};
