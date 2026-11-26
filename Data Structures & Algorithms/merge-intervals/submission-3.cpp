class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });

        std::vector<std::vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int>& prevInterval = mergedIntervals.back();
            if (intervals[i][0] > prevInterval[1]) {
                mergedIntervals.push_back(intervals[i]);
                continue;
            }

            prevInterval[1] = std::max(prevInterval[1], intervals[i][1]);
        }

        return mergedIntervals;
    }
};
