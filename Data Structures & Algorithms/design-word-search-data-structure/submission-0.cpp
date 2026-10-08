class WordDictionary {
private:
    std::array<WordDictionary*, 26> children{};
    bool isEndOfWord = false;

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new WordDictionary();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, this);
    }
    
private:
    bool search(string& word, int idx, WordDictionary* node) {
        WordDictionary* curr = node;

        for (int j = idx; j < word.size(); ++j) {
            char c = word[j];
            if (c == '.') {
                for (auto dict : curr->children) {
                    if (dict && search(word, j + 1, dict)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!curr->children[c - 'a']) {
                    return false;
                }
                curr = curr->children[c - 'a'];
            }
        }
        return curr->isEndOfWord;
    }
};
