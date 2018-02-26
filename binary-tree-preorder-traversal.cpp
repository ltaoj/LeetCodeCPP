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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v_pr, v_l, v_r;
        if (!root) return v_pr;
        v_pr.push_back(root->val);
        v_l = preorderTraversal(root->left);
        v_pr.insert(v_pr.end(), v_l.begin(), v_l.end());
        v_r = preorderTraversal(root->right);
        v_pr.insert(v_pr.end(), v_r.begin(), v_r.end());
        return v_pr;
    }
};