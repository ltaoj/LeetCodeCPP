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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        vector<vector<int>> v;
        if(root == NULL){
            return v;
        }
        int count = q.size();
        while(!q.empty()) {
            vector<int> vTmp;
            while(count-- > 0) {
                TreeNode* tmp = q.front();
                q.pop();
                if(level%2==0) {
                    vTmp.push_back(tmp->val);
                } else {
                    vTmp.insert(vTmp.begin(), tmp->val);
                }
                if(tmp->left != NULL) {
                    q.push(tmp->left);
                }
                if(tmp->right != NULL) {
                    q.push(tmp->right);
                }
            }
            v.push_back(vTmp);
            count = q.size();
            level++;
        }
        return v;
    }
};