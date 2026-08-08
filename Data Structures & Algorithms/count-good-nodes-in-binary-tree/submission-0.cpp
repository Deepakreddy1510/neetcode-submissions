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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxi = INT_MIN;
        Recursion(root,maxi, ans);
        return ans;
    }

    void Recursion(TreeNode* root,int maxi, int& ans){
        if(root == nullptr) return;
        if(root->val >= maxi){
            ans++;
            maxi = max(maxi, root->val);
        }
        Recursion(root->left,maxi,ans);
        Recursion(root->right,maxi, ans);
    }
};
