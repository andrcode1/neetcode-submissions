class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> neededDifference;
        
        for (int i = 0; i < nums.size(); i++) {
            auto search = neededDifference.find(nums.at(i)); 
            if (search == neededDifference.end()) {
                neededDifference.insert({target - nums.at(i), i});
                continue;
            }
            if (search->second != i) {
                if (search->second >= i) {
                    return{i, search->second};
                }
                return{search->second, i};
            }
            
        }
        return {};
    }
};
