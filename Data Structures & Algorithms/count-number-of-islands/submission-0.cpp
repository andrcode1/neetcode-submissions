class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    exploreIslandBFS(grid, i, j, visited);
                    result++;
                }
            }
        }

        return result;
    }

private:
    static constexpr std::array<int, 4> rowDirection = {{1, 0, -1, 0}};
    static constexpr std::array<int, 4> colDirection = {{0, 1, 0, -1}};

    bool isValidNeighbor(vector<vector<char>>& grid, int row, int col) {
        int rowBoundary = grid.size();
        int colBoundary = grid[0].size();

        return (row >= 0 && row < rowBoundary && col >= 0 && col < colBoundary &&
                grid[row][col] == '1');
    }

    void exploreIslandBFS(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        std::queue<pair<int, int>> currentIsland;
        currentIsland.push({row, col});

        while (!currentIsland.empty()) {
            auto [currRow, currCol] = currentIsland.front();
            currentIsland.pop();

            for (int i = 0; i < 4; ++i) {
                int newRow = currRow + rowDirection[i];
                int newCol = currCol + colDirection[i];

                if (isValidNeighbor(grid, newRow, newCol) && !visited[newRow][newCol]) {
                    currentIsland.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
    }

};
