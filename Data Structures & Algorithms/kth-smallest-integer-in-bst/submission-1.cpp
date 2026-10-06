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

class Solution {
public:
    void kthSmallest(TreeNode* root, int& k, int& result) {
        if (!root) {
            return;
        }

        kthSmallest(root->left, k, result);

        if (--k == 0) {
            result = root->val;
            return;
        }

        kthSmallest(root->right, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        kthSmallest(root, k, result);
        return result;
    }
};
