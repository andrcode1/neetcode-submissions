/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        if (!res.empty()) {
            res.pop_back(); // for leading ","
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return dfsDeserialize(data, i);
    }

private:
    void dfsSerialize(TreeNode* node, string& res) {
        if (!node) {
            res += "N,";
            return;
        }
        res += to_string(node->val);
        res += ',';
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(string& str, int& i) {
        if (str[i] == 'N') {
            i += 2; // passes "N,"
            return nullptr;
        }
        int left = i;
        while (std::isdigit(str[i]) || str[i] == '-') {
            i++;
        }
        TreeNode* node = new TreeNode(stoi(str.substr(left, i - left)));
        i++; // for ","
        node->left = dfsDeserialize(str, i);
        node->right = dfsDeserialize(str, i);
        return node;
    }
};
