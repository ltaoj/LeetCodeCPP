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
    bool isSymmetric(TreeNode *root) {
        return checkSame(root, root);
    }
    
    bool checkSame(TreeNode *n1, TreeNode *n2) {
        if (n1 == NULL && n2 == NULL) {
            return true;
        }
        if ((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL)) {
            return false;
        }
        return n1->val == n2->val && checkSame(n1->left, n2->right) && checkSame(n1->right, n2->left);
    }
};