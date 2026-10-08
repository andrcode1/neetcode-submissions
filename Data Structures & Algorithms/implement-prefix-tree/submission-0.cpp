class PrefixTree {
private:
    std::unordered_map<char, PrefixTree*> children;
    bool isEndOfWord = false;

public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            if (!curr->children[c]) {
                PrefixTree* next = new PrefixTree();
                curr->children[c] = next;
                curr = next;
            } else {
                curr = curr->children[c];
            }
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for (char c : word) {
            if (!curr->children[c]) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for (char c : prefix) {
            if (!curr->children[c]) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
