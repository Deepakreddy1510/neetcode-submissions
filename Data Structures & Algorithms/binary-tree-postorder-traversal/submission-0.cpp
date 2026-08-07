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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorderHelper(root,arr);
        return arr;
    }

    void postorderHelper(TreeNode* root, vector<int>& arr){
        if(root == nullptr) return;
        postorderHelper(root->left,arr);
        postorderHelper(root->right,arr);
        arr.push_back(root->val);
    }
};