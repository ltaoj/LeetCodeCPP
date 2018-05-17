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
private:
    int MIN_INT = ~((unsigned)(-1) >> 1);
    int maxSum = MIN_INT;
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int maxPath(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));
        int sum = left + root->val + right;
        if (sum > maxSum) {
            maxSum = sum;
        }
        return root->val + max(left, right);
    }
    
public: 
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        maxPath(root);
        return maxSum;
    }
};
