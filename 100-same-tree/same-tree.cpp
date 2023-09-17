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
    void getInOrder(TreeNode* t, vector<int>& inOrder) {
        if(t==NULL) {
            inOrder.emplace_back(NULL);
            return;
        }

        inOrder.emplace_back(t->val);
        getInOrder(t->left, inOrder);
        getInOrder(t->right, inOrder);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vecP;
        getInOrder(p, vecP);

        vector<int> vecQ;
        getInOrder(q, vecQ);

        if(vecP.size() != vecQ.size())
            return false;

        int n = vecQ.size();
        for(int i=0; i<n; i++)
            // cout<<vecP[i]<<" "<<vecQ[i]<<endl;
            if(vecP[i] != vecQ[i])
                return false;

        return true;        
    }
};