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
    int kthSmallest(TreeNode* root, int* counter, int k) {
        if (!root) {
            return -1;
        }

        int left = kthSmallest(root->left, counter, k);
        if (left != -1) {
            return left;
        }

        if (*counter == k) {
            return root->val;
        }
        (*counter)++;

        int right = kthSmallest(root->right, counter, k);
        if (right != -1) {
            return right;
        }

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 1;
        return kthSmallest(root, &counter, k);
    }
};
