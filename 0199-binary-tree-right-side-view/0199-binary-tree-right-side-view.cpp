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
    void rightview(TreeNode* root, int level, vector<int>& v){
        if(root==NULL) return;
        if(v.size()==level) v.push_back(root->val);
        rightview(root->right,level+1,v);
        rightview(root->left,level+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int>ans;
        rightview(root,level,ans);
        return ans;
        
    }
};