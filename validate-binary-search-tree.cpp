/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return solve(root, INT_MIN, INT_MAX);
    }
    
    bool solve(TreeNode *root, int lower, int upper) {
        if (!root) {
            return true;
        }
        
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        
        return solve(root->left, lower, root->val) && solve(root->right, root->val, upper);
    }
};