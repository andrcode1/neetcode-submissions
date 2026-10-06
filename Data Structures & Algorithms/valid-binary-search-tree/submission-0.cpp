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

    bool isValidBST(TreeNode* root, int leftParent, int rightParent) {
        if (!root) {
            return true;
        }
        if (root->val <= leftParent or root->val >= rightParent) {
            return false;
        }
        
        return isValidBST(root->left, leftParent, root->val) and isValidBST(root->right, root->val, rightParent);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
