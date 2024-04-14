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
private:
    int leftSum(TreeNode* root, bool isleft) {
        if(root == NULL) {
            return 0;
        }

        if(root->left==NULL && root->right==NULL) {
            if(isleft) {
                return root->val;
            } else {
                return 0;
            }
        }

        return leftSum(root->left, 1) + leftSum(root->right, 0);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return leftSum(root, 0);
    }
};