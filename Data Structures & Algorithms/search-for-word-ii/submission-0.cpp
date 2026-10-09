class Solution {
public:

    class TrieNode {
        private:
            std::array<TrieNode*, 26> children{};
            bool isEndOfWord = false;
            string storedWord;

        public:
            void insert(std::string word) {
                TrieNode* curr = this;
                for (char c : word) {
                    if (!curr->children[c - 'a']) {
                        curr->children[c - 'a'] = new TrieNode();
                    }
                    curr = curr->children[c - 'a'];
                }
                curr->isEndOfWord = true;
                curr->storedWord = word;
            }

            void search(
                TrieNode* node,
                char c, 
                pair<int,int> idx, 
                vector<vector<char>>& board, 
                std::vector<std::vector<int>>& seenIdxs,
                std::unordered_set<string>& res) 
            {
                if (!node->children[c - 'a']) {
                    return;
                }

                node = node->children[c - 'a'];
                if (node->isEndOfWord) {
                    res.insert(node->storedWord);
                }

                auto [i, j] = idx;
                seenIdxs[i][j] = 1;
                std::array<pair<int, int>, 4> offsets = {{{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}}};
                for (const auto& offset : offsets) {
                    if ((offset.first < 0 || offset.first >= board.size()) || 
                        (offset.second < 0 || offset.second >= board[i].size())
                        ) 
                    {
                        continue; // out of bounds
                    }

                    if (seenIdxs[offset.first][offset.second] == 1) {
                        continue;
                    }

                    node->search(node, board[offset.first][offset.second], offset, board, seenIdxs, res);
                }
                seenIdxs[i][j] = 0;
                return;
            }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* dict = new TrieNode();
        for (auto& word : words) {
            dict->insert(word);
        }

        std::unordered_set<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                std::vector<std::vector<int>> seenIdxs(board.size(), std::vector<int>(board[i].size(), 0));
                seenIdxs[i][j] = 1;
                dict->search(dict, board[i][j], {i, j}, board, seenIdxs, res);
            }
        }

        std::vector<std::string> resVec(res.begin(), res.end());
        return resVec;
    }
};