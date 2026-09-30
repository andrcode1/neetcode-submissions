class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> neededDifference;
        neededDifference.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            neededDifference.insert({target - nums.at(i), i});
        }
        for (int i = 0; i < nums.size(); i++) {
            auto search = neededDifference.find(nums.at(i)); 
            if (search == neededDifference.end()) {
                continue;
            }
            if (search->second != i) {
                auto [min, max] = std::minmax(i, search->second);
                return{min, max};
            }
        }
        return {};
    }
};
