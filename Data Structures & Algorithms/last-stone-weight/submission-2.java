class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxStones = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone : stones) {
            maxStones.offer(stone);
        }

        while (maxStones.size() > 1) {
            int first = maxStones.poll();
            int second = maxStones.poll();

            if (first > second) {
                maxStones.offer(first - second);
            }
        }

        if (!maxStones.isEmpty()) {
            return maxStones.peek();
        }
        return 0;
    }
}
