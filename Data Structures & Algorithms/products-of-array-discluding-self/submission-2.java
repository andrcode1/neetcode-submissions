class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] leftToRight = new int[nums.length];
        int[] rightToLeft = new int[nums.length];

        int product = 1;
        for (int i = 0; i < nums.length; ++i) {
            product = product * nums[i];
            leftToRight[i] = product;
        }

        product = 1;
        for (int i = nums.length - 1; i >= 0; --i) {
            product = product * nums[i];
            rightToLeft[i] = product;
        }

        int[] res = new int[nums.length];
        res[0] = rightToLeft[1];
        res[res.length - 1] = leftToRight[leftToRight.length - 2];

        for (int i = 1; i < nums.length - 1; ++i) {
            res[i] = leftToRight[i-1] * rightToLeft[i+1];
        }

        return res;
    }
}  
