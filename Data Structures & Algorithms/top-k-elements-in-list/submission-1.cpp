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

            std::vector<pair<int, int>> sortedElementOccurences;
            for (auto it = elementOccurences.begin(); it != elementOccurences.end(); it++) {
                sortedElementOccurences.push_back({it->first, it->second});
            }

            std::sort(sortedElementOccurences.begin(), sortedElementOccurences.end(),
            [](std::pair<int, int> element1, std::pair<int, int> element2) {
                return element1.second > element2.second;
            });
            
            std::vector<int> result;
            result.reserve(k);
            auto itSorted = sortedElementOccurences.begin();
            for (int i = 0; i < k; i++) {
                result.push_back(itSorted->first);
                itSorted++;
            }
            return result;

        }
};
