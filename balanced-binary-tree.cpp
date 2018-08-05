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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return subTreeDepth(root, depth);
    }
    
    // depth表示从子树中最下边的那个节点到当前节点的距离
    bool subTreeDepth(TreeNode *tree, int &depth) {
        if (!tree) {
            depth = 0;
            return true;
        }
        
        int left, right;
        if (subTreeDepth(tree->left, left) && subTreeDepth(tree->right, right)) {
            if (abs(left-right) <= 1) {
                depth = 1 + max(left, right);
                return true;
            }
        }
        
        return false;
    }
};