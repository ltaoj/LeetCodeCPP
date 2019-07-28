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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        vector<vector<int>> v;
        if (root == NULL) {
            return v;
        }
        
        while (!q.empty()) {
            vector<int> tmp;
            int count = q.size();
            while (count-- > 0) {
                TreeNode* pNode = q.front();
                q.pop();
                tmp.push_back(pNode->val);
                if (pNode->left != NULL) {
                    q.push(pNode->left);
                }
                if (pNode->right != NULL) {
                    q.push(pNode->right);
                }
            }
            v.push_back(tmp);
        }
        return v;
    }
};