class Solution {
    public int numSquares(int n) {
        // dp[i] = the least number of perfect square numbers that sum to i

        // dp[i] = minimum + 1
        // hold a list of all the perfect square numbers which are < i
        // for loop through these numbers
        // check dp[i - perfectSqureNumber]
        // pick the minimum

        int[] dp = new int[n + 1];
        List<Integer> perfectSquares = new ArrayList<>();

        dp[1] = 1;
        perfectSquares.add(1);

        for (int i = 2; i <= n; i++) {
            int sqrt = (int) Math.sqrt(i);
            if (sqrt * sqrt == i) {
                perfectSquares.add(i);
                dp[i] = 1;
                continue;
            }

            // dp[i] = 1 + Collections.min((a, b) -> Integer.compare(a, b));
            int min = n;
            for (int num : perfectSquares) {
                min = Math.min(min, dp[i - num]);
            }

            dp[i] = min + 1;
        }

        return dp[n];
    }
}