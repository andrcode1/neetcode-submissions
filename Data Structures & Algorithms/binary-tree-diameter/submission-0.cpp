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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int max = 0;
        postorderMaxDiameter(root, max);
        return max;
    }

private:
    int postorderMaxDiameter(TreeNode* root, int& max) {
        int heightLeft = 0;
        if (root->left) {
            heightLeft += 1 + postorderMaxDiameter(root->left, max);
        }
        int heightRight = 0;
        if (root->right) {
            heightRight = 1 + postorderMaxDiameter(root->right, max);
        }
        max = std::max(max, heightLeft + heightRight);
        return std::max(heightLeft, heightRight);
    }
};
