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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right && sum-root->val == 0)
            return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
/*class Solution { // 原答案
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
             return pathSumInternal(root, sum);
        }
        return false;
    }
private:
    bool pathSumInternal(TreeNode *node, int left) {
        if (!node->left && !node->right) {
            if (left - node->val == 0) {
                return true;
            }
        } else {
            if (node->left && pathSumInternal(node->left, left-node->val)) {
                return true;
            }
            if (node ->right && pathSumInternal(node->right, left-node->val)) {
                return true;
            }
        }
        return false;
    }
};
*/
