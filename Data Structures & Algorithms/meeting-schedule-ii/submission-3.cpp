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
        std::map<int, int> update; // time : 1/-1 if a meeting started/ended
        for (const auto& interval : intervals) {
            update[interval.start] += 1;
            update[interval.end] += -1;
        }

        int meetingRooms = 0;
        int currMeetingRooms = 0;
        for (auto& [key, value] : update) {
            currMeetingRooms += value;
            meetingRooms = std::max(meetingRooms, currMeetingRooms);
        }

        return meetingRooms;
    }
};
