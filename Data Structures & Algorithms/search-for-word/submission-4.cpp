class Solution {
private:
    string word;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == this->word[0]) {
                    board[i][j] = '#';
                    if (backtrack({i, j}, board, 1)) {
                        return true;
                    }
                    board[i][j] = this->word[0];
                }
            }
        }
        return false;
    }

private:
    bool backtrack(pair<int, int> charIdxs, vector<vector<char>>& board, int idx) {
        if (idx == word.size()) {
            return true;
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

            if (board[c.first][c.second] == '#') {
                continue;
            }
            
            if (board[c.first][c.second] == word[idx]) {
                board[c.first][c.second] = '#';
                if (backtrack(c, board, idx + 1)) {
                    return true;
                }
                board[c.first][c.second] = word[idx];
            }
        }
        return false;
    }
};
