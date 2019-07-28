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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size()==0)
            return NULL;
        int rootval = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootval);
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), rootval);
        vector<int> leftin = vector<int>(inorder.begin(), iter);
        vector<int> rightin = vector<int>(iter+1, inorder.end());
        if (leftin.size() > 0) {
            vector<int> leftpo = vector<int>(postorder.begin(), postorder.begin()+leftin.size());
            root->left = buildTree(leftin, leftpo);
        }
        if (rightin.size() > 0) {
            vector<int> rightpo = vector<int>(postorder.begin()+leftin.size(), postorder.begin()+leftin.size()+rightin.size());
            root->right = buildTree(rightin, rightpo);
        }
        return root;
    }
};