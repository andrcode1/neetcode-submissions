class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> neededDifference = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            neededDifference.put(target - nums[i], i);
        }

        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int j = neededDifference.getOrDefault(nums[i], -1);
            if (j != i && j != -1) {
                res[0] = Math.min(i, j);
                res[1] = Math.max(i, j);
            }
        }
        return res;
    }
}

// 4 5 6
// 6 5 4
