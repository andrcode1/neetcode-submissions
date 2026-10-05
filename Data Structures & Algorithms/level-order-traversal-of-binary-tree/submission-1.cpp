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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (!node) {
                continue;
            }

            while (answer.size() < level + 1) {
                answer.push_back(vector<int>());
            }
            answer[level].push_back(node->val);

            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }

        return answer;
    }
};
