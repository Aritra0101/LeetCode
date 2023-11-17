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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double avg = 0;
        int count = 0;

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()) {
            queue<TreeNode*> que;
            TreeNode* node;
            avg = 0;
            count = qu.size();
            while(!qu.empty()) {
                node = qu.front();
                qu.pop();
                avg += node->val;
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            res.emplace_back(avg/count);
            qu = que;
        }

        return res;
    }
};