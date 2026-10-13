class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> paths(n, 0);
        if (n < 2) {
            return n; 
        }
        paths[0] = 1;
        paths[1] = 2;
        for (int i = 2; i < n; ++i) {
            paths[i] = paths[i-1] + paths[i-2];
        }
        return paths[n-1];
    }
};
