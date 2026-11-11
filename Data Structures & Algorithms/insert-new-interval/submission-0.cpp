class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;

        if (intervals.empty()) {
            return {newInterval};
        }

        for (int i = 0; i < intervals.size(); ++i) {
            if (!isOverlapping(intervals[i], newInterval)) {
                if (intervals[i][0] > newInterval[0]) {
                    mergedIntervals = vector<vector<int>>(intervals.begin(), intervals.begin() + i);
                    mergedIntervals.push_back(newInterval);
                    mergedIntervals.insert(mergedIntervals.end(), intervals.begin() + i, intervals.end());
                    return mergedIntervals;
                }

                if (i == intervals.size() - 1) {
                    mergedIntervals = intervals;
                    mergedIntervals.push_back(newInterval);
                    return mergedIntervals;
                }

                continue;
            }

            int firstOverlap = i;
            int lastOverlap = firstOverlap;
            while (lastOverlap < intervals.size() && isOverlapping(intervals[lastOverlap], newInterval)) {
                lastOverlap++;
            }
            lastOverlap -= 1;

            int minStart = std::min(intervals[firstOverlap][0], newInterval[0]);
            int maxEnd = std::max(intervals[lastOverlap][1], newInterval[1]);
            vector<int> mergedInterval = {minStart, maxEnd};

            intervals[firstOverlap] = mergedInterval;
            if (firstOverlap < lastOverlap) {
                intervals.erase(intervals.begin() + firstOverlap + 1, intervals.begin() + lastOverlap + 1);
            }

            return intervals;
        }

        return mergedIntervals;
    }

private:
    bool isOverlapping(vector<int>& interval1, vector<int>& interval2) {
        int latestStart = std::max(interval1[0], interval2[0]);
        int earliestEnd = std::min(interval1[1], interval2[1]);

        return latestStart <= earliestEnd;
    }
};
