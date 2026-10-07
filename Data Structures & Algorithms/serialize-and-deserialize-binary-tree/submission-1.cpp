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
    
    void dfs_serialize(TreeNode* root, string& str) {
        str += std::to_string(root->val);
        if (root->left && root->right) {
            str += "[";
            dfs_serialize(root->left, str);
            str += " ";
            dfs_serialize(root->right, str);
            str += "]";
        }
        if (root->left && !root->right) {
            str += "[";
            dfs_serialize(root->left, str);
            str += " N]";
        }
        if (!root->left && root->right) {
            str += "[N ";
            dfs_serialize(root->right, str);
            str += "]";
        }
        if (!root->left && !root->right) {
            return;
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedString;
        if (!root) {
            serializedString = "N";
        } else {
            dfs_serialize(root, serializedString);
        }
        return serializedString;
    }

    // 1[2 3[4 5]]
    TreeNode* dfs_deserialize(string& data, int& idx) {
        if (data[idx] == 'N') {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode();
        if (std::isdigit(data[idx])) {
            int val = 0;
            int left = idx;
            while (std::isdigit(data[idx])) {
                idx++;
            }
            val = std::stoi(data.substr(left, idx - left));
            node->val = val;
        }
        if (data[idx] == '[') {
            idx++;
            node->left = dfs_deserialize(data, idx);
            if (data[idx] == ' ') {
                idx++;
            }
            node->right = dfs_deserialize(data, idx);
            if (data[idx] == ']') {
                idx++;
            }
        }
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int strIndex = 0;
        return dfs_deserialize(data, strIndex);
    }
};
