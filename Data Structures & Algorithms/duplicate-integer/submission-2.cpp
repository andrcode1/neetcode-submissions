class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> duplicateChecker;
        for (int n : nums) {
            auto inserted = duplicateChecker.insert(n);
            if (!inserted.second) {
                return true;
            }
        }
        return false;
    }
};