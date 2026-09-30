class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> elementOccurences;
            for (int n : nums) {
                if (elementOccurences.contains(n)) {
                    elementOccurences[n]++;
                } else {
                    elementOccurences.insert({n, 0});
                }	
            }

            std::vector<std::list<int>> elementOccurencesBuckets;
            elementOccurencesBuckets.resize(nums.size());
            for (auto it = elementOccurences.begin(); it != elementOccurences.end(); it++) {
                elementOccurencesBuckets[it->second].push_back(it->first);
            }
            
            std::vector<int> result;
	        int counter = 0;
            for (int i = nums.size() - 1; i >= 0; i--) {
	            if (counter == k) {
		            break;
	            }
                if (!elementOccurencesBuckets[i].empty()) {
		            for (auto it = elementOccurencesBuckets[i].begin();
                        it != elementOccurencesBuckets[i].end();
                        it++) 
                    {
			            result.push_back(*it);
			            counter++;
		            }
	            }
            }
            return result;

        }

};
