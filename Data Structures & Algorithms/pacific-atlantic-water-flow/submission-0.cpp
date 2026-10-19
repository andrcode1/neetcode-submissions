class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> canReachPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> canReachAtlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> result;

        for (int j = 0; j < cols; ++j) {
            if (!canReachPacific[0][j]) {
                expandOceanDFS(canReachPacific, 0, j, heights);
            }
        }
        for (int i = 0; i < rows; ++i) {
            if (!canReachPacific[i][0]) {
                expandOceanDFS(canReachPacific, i, 0, heights);
            }
        }

        for (int j = 0; j < cols; ++j) {
            if (!canReachAtlantic[rows - 1][j]) {
                expandOceanDFS(canReachAtlantic, rows - 1, j, heights);
            }
        }
        for (int i = 0; i < rows; ++i) {
            if (!canReachAtlantic[i][cols - 1]) {
                expandOceanDFS(canReachAtlantic, i, cols - 1, heights);
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }

private:

    static constexpr std::array<int, 4> rowDirection = {{1, 0, -1, 0}};
    static constexpr std::array<int, 4> colDirection = {{0, 1, 0, -1}};

    bool isValidNeighbor(int row, int col, int newRow, int newCol, vector<vector<int>>& heights) {
        return (newRow >= 0 && newRow < heights.size() && 
                newCol >= 0 && newCol < heights[0].size() &&
                heights[newRow][newCol] >= heights[row][col]);
    }

    void expandOceanDFS(vector<vector<bool>>& ocean, int row, int col, vector<vector<int>>& heights) {
        ocean[row][col] = true;
        for (int i = 0; i < 4; ++i) {
            int newRow = row + rowDirection[i];
            int newCol = col + colDirection[i];

            if (isValidNeighbor(row, col, newRow, newCol, heights) && !ocean[newRow][newCol]) {
                expandOceanDFS(ocean, newRow, newCol, heights);
            }
        }
    }
};

// 5 5 5 5
// 4 4 4 4
// 5 5 5 5