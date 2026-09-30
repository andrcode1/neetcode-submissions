class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> duplicateChecker;
        for (int n : nums) {
            if (!duplicateChecker.insert(n).second) {
                return true;
            }
        }
        return false;
    }
};