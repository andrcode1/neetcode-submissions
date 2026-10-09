class Solution {
private:
    vector<vector<int>> res;

    void backtrack(vector<int>& combination, int currentSum, int idx, vector<int>& nums, int target) {
        if (currentSum == target) {
            res.push_back(combination);
        }

        for (int i = idx; i < nums.size(); ++i) {
            int n = nums[i];

            if (currentSum + n > target) {
                continue;
            }

            combination.push_back(n);
            backtrack(combination, currentSum + n, i, nums, target);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        backtrack(combination, 0, 0, nums, target);
       
        return res;
    }
};
