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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;

        qu.push(root);
        
        int resVal=root->val, resLev=1;
        int sum=0, lev=0;
        while(!qu.empty()) {
            sum = 0;
            lev += 1;

            int size = qu.size();
            for(int i=0; i<size; i++) {
                TreeNode* ptr = qu.front();
                qu.pop();

                sum += ptr->val;

                if(ptr->left)
                    qu.push(ptr->left);
                if(ptr->right)
                    qu.push(ptr->right);
            }

            if(sum > resVal) {
                resVal = sum;
                resLev = lev;
            }
        }
        return resLev;
    }
};