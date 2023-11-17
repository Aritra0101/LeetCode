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
    bool isSubtreeCheck(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) {
            return true;
        }
        if((root!=NULL && subRoot==NULL) || (root==NULL && subRoot!=NULL)) {
            return false;
        }
        if(root->val != subRoot->val) {
            return false;
        }
        return isSubtreeCheck(root->left, subRoot->left) && isSubtreeCheck(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        set<TreeNode*> mySet;

        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;
        while(!qu.empty()) {
            node = qu.front();
            qu.pop();

            if(node->val == subRoot->val) {
                mySet.insert(node);
            }
            if(node->left)
                qu.push(node->left);
            if(node->right)
                qu.push(node->right);
        }

        for(TreeNode* node: mySet) {
            if(isSubtreeCheck(node, subRoot))
                return true;
            else
                continue;
        }
        return false;
    }
};