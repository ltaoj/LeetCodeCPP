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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) 
            return NULL;
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), rootval);
        vector<int> leftin = vector<int>(inorder.begin(), iter);
        vector<int> rightin = vector<int>(iter+1, inorder.end());
        int leftsize = leftin.size();
        int rightsize = rightin.size();
        if (leftsize > 0) {
            vector<int> leftpre = vector<int>(preorder.begin()+1, preorder.begin()+1+leftsize);
            root->left = buildTree(leftpre, leftin);
        }
        if (rightsize > 0) {
            vector<int> rightpre = vector<int>(preorder.begin()+1+leftsize, preorder.begin()+1+leftsize+rightsize);
            root->right = buildTree(rightpre, rightin);
        }
        return root;
    }
};