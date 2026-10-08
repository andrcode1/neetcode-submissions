class PrefixTree {
private:
    std::array<PrefixTree*, 26> children{};
    bool isEndOfWord = false;

public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                PrefixTree* next = new PrefixTree();
                curr->children[c - 'a'] = next;
                curr = next;
            } else {
                curr = curr->children[c - 'a'];
            }
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for (char c : prefix) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};
