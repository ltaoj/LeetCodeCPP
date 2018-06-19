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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<int> temp;
        if (root) {
            temp.push_back(root->val);
            pathSumInternal(root, sum, temp, paths);
            temp.pop_back();
        }
        return paths;
    }
private:
    void pathSumInternal(TreeNode *node, int left, vector<int>& temp, vector<vector<int> >& paths) {
        if (!node->left && !node->right) {
            if (left - node->val == 0) {
                vector<int> path(temp.begin(), temp.end());
                paths.push_back(path);
            }
        } else {
            /*if (node->val > left)// 这里一开始以为都是正数，所以进行了剪枝，但是测试用例还有负数
                return;*/
            if (node->left) {
                temp.push_back(node->left->val);
                pathSumInternal(node->left, left-node->val, temp, paths);
                temp.pop_back();
            }
            if (node ->right) {
                temp.push_back(node->right->val);
                pathSumInternal(node->right, left-node->val, temp, paths);
                temp.pop_back();
            }
        }
    }
};
