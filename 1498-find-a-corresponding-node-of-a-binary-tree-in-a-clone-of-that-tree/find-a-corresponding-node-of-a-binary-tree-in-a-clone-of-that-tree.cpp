/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push( {original, cloned} );
        pair<TreeNode*, TreeNode*> pp;
        while(!qu.empty()) {
            pp = qu.front();
            qu.pop();

            if(target == pp.first) {
                return pp.second;
            }
            
            if(pp.first->left)
                qu.push( {pp.first->left, pp.second->left} );
            if(pp.first->right)
                qu.push( {pp.first->right, pp.second->right} );
        }

        return NULL;
    }
};