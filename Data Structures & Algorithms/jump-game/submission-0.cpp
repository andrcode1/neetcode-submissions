class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> canReach(nums.size(), false);
        canReach[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (!canReach[i]) {
                continue;
            }

            for (int jumpTo = i + 1; jumpTo <= i + nums[i]; ++jumpTo) {
                canReach[jumpTo] = true;
            }
        }

        return canReach.back();
    }
};
