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
    int minMeetingRooms(vector<Interval>& intervals) {
        int meetingRooms = 0;

        std::sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2){
            return interval1.start < interval2.start;
        });

        std::unordered_map<int, int> update; // time : 1/-1 if a meeting started/ended
        int maxEndTime = 0;
        for (const auto& interval : intervals) {
            update[interval.start] += 1;
            update[interval.end] += -1;
            maxEndTime = std::max(maxEndTime, interval.end);
        }

        int currMeetingRooms = 0;
        for (int i = 0; i <= maxEndTime; i++) {
            currMeetingRooms += update[i];
            meetingRooms = std::max(meetingRooms, currMeetingRooms);
        }

        return meetingRooms;
    }
};
