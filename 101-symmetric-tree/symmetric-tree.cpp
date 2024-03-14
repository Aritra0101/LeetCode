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
    vector<int> leftInLevel(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> vec;

        if(root)
            qu.push(root);

        while(!qu.empty()) {
            TreeNode* node = qu.front(); 
            qu.pop();

            if(node)
                vec.emplace_back(node->val);
            else
                vec.emplace_back(123);

            if(node) {
                qu.push(node->left);
                qu.push(node->right);
            }
        }

        return vec;
    }

    vector<int> rightInLevel(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> vec;

        if(root)
            qu.push(root);

        while(!qu.empty()) {
            TreeNode* node =  qu.front();
            qu.pop();

            if(node)
                vec.emplace_back(node->val);
            else
                vec.emplace_back(123);

            if(node) {
                qu.push(node->right);
                qu.push(node->left);
            }
        }

        return vec;
    }
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> left = leftInLevel(root);
        vector<int> right = rightInLevel(root);  

        // for(int e: left) {
        //     cout<<e<<" ";
        // }
        // cout<<endl;

        // for(int e: right) {
        //     cout<<e<<" ";
        // }
        // cout<<endl;

        int n = left.size();
        int m = right.size();  

        for(int i=0; i<n; i++) {
            if(left[i] != right[i]) {
                return false;
            }
        }

        return true;
    }
};