class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> uniquePathsToSquare(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            uniquePathsToSquare[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            uniquePathsToSquare[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                uniquePathsToSquare[i][j] = uniquePathsToSquare[i-1][j] + uniquePathsToSquare[i][j-1];
            }
        }

        return uniquePathsToSquare[m-1][n-1];
    }
};

// 1 1
// 1 2
// 1 3