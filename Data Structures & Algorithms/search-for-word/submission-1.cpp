class Solution {
private:
    vector<vector<char>> board;
    string word;
    bool found = false;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visited.assign(board.size(), vector<int>(board[0].size(), 0));
                    visited[i][j] = 1;
                    backtrack({i, j}, visited, 1);
                }
            }
        }
        return found;
    }

private:
    void backtrack(pair<int, int> charIdxs, vector<vector<int>>& visited, int idx) {
        if (idx == word.size()) {
            found = true;
            return;
        }

        std::array<pair<int, int>, 4> candidates = 
            {{{charIdxs.first + 1, charIdxs.second},
            {charIdxs.first, charIdxs.second + 1},
            {charIdxs.first - 1, charIdxs.second},
            {charIdxs.first, charIdxs.second - 1}}};

        for (auto& c : candidates) {
            if (c.first < 0 || c.first >= board.size() ||
                c.second < 0 || c.second >= board[0].size()) {
                    continue;
            }

            if (visited[c.first][c.second] == 1) {
                continue;
            }
            
            if (board[c.first][c.second] == word[idx]) {
                visited[c.first][c.second] = 1;
                backtrack(c, visited, idx + 1);
                visited[c.first][c.second] = 0;
            }
        }
    }
};
