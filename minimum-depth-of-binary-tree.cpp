class Solution {
public:
    int run(TreeNode *root) {
        if (root == NULL)
            return 0;
        else
            return findDepth(root, 1);
        
    }
    
    int findDepth(TreeNode *node, int depth) {
        if (node->left == NULL && node->right == NULL)
            return depth;
        int leftDepth, rightDepth;
        if (node->left != NULL)
            leftDepth = findDepth(node->left, depth+1);
        else
            return findDepth(node->right, depth+1);
        if (node->right != NULL)
            rightDepth = findDepth(node->right, depth+1);
        else 
            return leftDepth;
        return leftDepth < rightDepth ? leftDepth : rightDepth;
    }
};