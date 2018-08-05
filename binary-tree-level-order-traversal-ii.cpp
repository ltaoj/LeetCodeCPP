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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        backOrder(result, root, 0);
        vector<vector<int> > reverse;
        for(int i = result.size()-1;i >= 0;i--) {
            reverse.push_back(result.at(i));
        }
        return reverse;
    }
private:
    void backOrder(vector<vector<int> > &result, TreeNode *root, int level) {
        if (root == NULL) return;
        // 先放置当前节点
        vector<int> vec_cur_level;
        if (result.size() <= level) {
            result.push_back(vec_cur_level);
        } else {
            vec_cur_level = result[level];
        }
        
        vec_cur_level.push_back(root->val);
        result[level] = vec_cur_level;
        backOrder(result, root->left, level+1);
        backOrder(result, root->right, level+1);
    }
};