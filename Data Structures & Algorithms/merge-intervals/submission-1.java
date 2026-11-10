class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0]));

        List<int[]> mergedIntervals = new ArrayList<>();
        mergedIntervals.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            var interval = intervals[i];
            var prevInterval = mergedIntervals.getLast();

            int latestStart = Math.max(interval[0], prevInterval[0]);
            int earliestEnd = Math.min(interval[1], prevInterval[1]);

            if (earliestEnd < latestStart) {
                mergedIntervals.add(interval);
                continue;
            }

            prevInterval[0] = Math.min(interval[0], prevInterval[0]);
            prevInterval[1] = Math.max(interval[1], prevInterval[1]);
        }

        int[][] res = mergedIntervals.toArray(new int[mergedIntervals.size()][]);

        return res;
    }
}
