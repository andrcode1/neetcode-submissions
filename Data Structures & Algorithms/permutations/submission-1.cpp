class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        backtrack(path, nums);
        return res;
    }

private:
    void backtrack(vector<int>& path, vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (auto& n : nums) {
            if (std::find(path.begin(), path.end(), n) != path.end()) {
                continue;
            }

            path.push_back(n);
            backtrack(path, nums);
            path.pop_back();
        }
    }
};