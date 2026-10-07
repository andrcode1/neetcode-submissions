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
    std::unordered_map<int, std::pair<int, int>> nodeIndeces; // node->val: indexPre, indexIn

    TreeNode* buildTree(int indexPre, vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[indexPre]);

        int mid = nodeIndeces[node->val].second;

        int indexPreOfLeft = -1001;
        int indexPreOfRight = 1001;

        for (int i = 0; i < preorder.size(); ++i) {
            int val = preorder[i];
            int index = nodeIndeces[val].second;
            if (index < mid && index >= l) {
                indexPreOfLeft = i;
                break;
            }
        }
        for (int i = 0; i < preorder.size(); ++i) {
            int val = preorder[i];
            int index = nodeIndeces[val].second;
            if (index > mid && index <= r) {
                indexPreOfRight = i;
                break;
            }
        }

        node->left = buildTree(indexPreOfLeft, preorder, inorder, l, mid-1);
        node->right = buildTree(indexPreOfRight, preorder, inorder, mid+1, r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); ++i) {
            nodeIndeces[preorder[i]].first = i;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            nodeIndeces[inorder[i]].second = i;
        }
        return buildTree(0, preorder, inorder, 0, preorder.size() - 1);
    }
};