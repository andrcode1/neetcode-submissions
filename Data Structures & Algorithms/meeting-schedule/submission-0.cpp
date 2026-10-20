/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2) {
            return i1.start < i2.start;
        });

        for (int i = 1; i < intervals.size(); ++i) {
            if (hasOverlap(intervals[i], intervals[i-1])) {
                return false;
            }
        }
        return true;
    }

private:
    bool hasOverlap(Interval i1, Interval i2) {
        return std::max(i1.start, i2.start) < std::min(i1.end, i2.end);
    }
};
