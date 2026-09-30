class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> neededDifference;
        
        for (int i = 0; i < nums.size(); i++) {
            auto search = neededDifference.find(nums.at(i)); 
            if (search != neededDifference.end()) {
                return{search->second, i};
            }
            neededDifference.emplace(target - nums.at(i), i);   
        }
        return {};
    }
};
