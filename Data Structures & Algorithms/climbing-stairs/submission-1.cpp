class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> paths(n, 0);
        paths[0]++;
        if (n > 1) {
            paths[1]++; 
        }
        for (int i = 0; i < n - 1; ++i) {
            paths[i+1] += paths[i];
            if (i < n - 2) {
                paths[i+2] += paths[i];
            }
        }
        return paths[n-1];
    }
};
