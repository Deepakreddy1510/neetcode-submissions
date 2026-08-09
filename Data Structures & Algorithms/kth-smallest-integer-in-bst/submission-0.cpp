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
    void inorderTraversal(TreeNode* root,int& cnt,int k,int& ksmallest){
        if(root == nullptr || cnt >= k){
            return;
        }
        inorderTraversal(root->left,cnt,k,ksmallest);
        cnt++;
        if(cnt == k){
            ksmallest = root->val;
            return;
        }
        inorderTraversal(root->right,cnt,k,ksmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ksmallest = -1;
        inorderTraversal(root,cnt,k,ksmallest);
        return ksmallest;
    }
};
