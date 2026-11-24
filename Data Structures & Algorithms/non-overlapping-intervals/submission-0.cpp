class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2) {
            return interval1[0] < interval2[0];
        });
        int kept = 1;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) { // conflict
                prevEnd = std::min(prevEnd, intervals[i][1]);
                continue;
            }

            prevEnd = intervals[i][1];
            kept++;
        }

        return intervals.size() - kept;
    }
};
