class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i++;
        }
        mergedIntervals.push_back(newInterval);

        while (i < intervals.size()) {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }
        
        return mergedIntervals;
    }
};
