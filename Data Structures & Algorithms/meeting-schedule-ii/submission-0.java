/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        TreeMap<Integer, Integer> activeMeetings = new TreeMap<>();
        for (Interval i : intervals) {
            activeMeetings.put(i.start, activeMeetings.getOrDefault(i.start, 0) + 1);
            activeMeetings.put(i.end, activeMeetings.getOrDefault(i.end, 0) - 1);
        }
        int prev = 0;
        int maxNumberOfConflicts = 0;
        for (int key : activeMeetings.keySet()) {
            prev += activeMeetings.get(key);
            maxNumberOfConflicts = Math.max(maxNumberOfConflicts, prev);
        }
        return maxNumberOfConflicts;
    }
}
