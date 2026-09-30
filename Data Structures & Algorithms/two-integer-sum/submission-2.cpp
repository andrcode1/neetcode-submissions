class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_multimap<int, int> neededDifference;
        for (int i = 0; i < nums.size(); i++) {
            neededDifference.insert({target - nums.at(i), i});
        }

        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            bool found = false;
            auto range = neededDifference.equal_range(nums.at(i)); 
            for (auto it = range.first; it != range.second; it++) {
                if (it->second != i) {
                    result.push_back(i);
                    result.push_back(it->second);
                    found = true;
                    break;
                }
            }
            if (found == true) {
                break;
            }
        }
        return result;
    }
};
