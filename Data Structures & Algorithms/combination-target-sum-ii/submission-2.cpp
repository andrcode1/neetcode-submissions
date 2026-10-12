class Solution {
private:
    vector<vector<int>> result;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtrack({}, 0, 0, candidates, target);

        return result;
    }

private:
    void backtrack(vector<int> path, int currentSum, int idx, vector<int>& candidates, int target) {
        if (currentSum == target) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            if (currentSum + candidates[i] > target) {
                break;
            }

            path.push_back(candidates[i]);
            backtrack(path, currentSum + candidates[i], i + 1, candidates, target);
            path.pop_back();
            }
        }
};
