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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool balanced = true;
        BalancedCheck(root,balanced);
        return balanced;
    }

    int BalancedCheck(TreeNode* root,bool& balanced){
        if(root == nullptr) return 0;
        int lH = BalancedCheck(root->left,balanced);
        int rH = BalancedCheck(root->right,balanced);
        if(abs(lH - rH) > 1){
            balanced = false;
            return -1;
        }
        return max(lH,rH) + 1;
    }
};
