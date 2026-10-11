class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, 0, path);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int idx, vector<int>& path) {
        if (idx == nums.size()) {
            res.push_back(path);
            return;
        }

        path.push_back(nums[idx]);
        backtrack(nums, idx + 1, path);
        path.pop_back();
        backtrack(nums, idx + 1, path);
    }
};
