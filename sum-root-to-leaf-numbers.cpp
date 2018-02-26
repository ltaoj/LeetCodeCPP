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
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0, cur = 0;
        string nstr;
        findAndSum(root, sum, cur, nstr);
        return sum;
    }
    
private:
    void findAndSum(TreeNode *node, int &sum, int &cur, string &s) {
        s += to_string(node->val);
        if (!node->left && !node->right) {
            stringstream ss;
            ss << s;
            ss >> cur;
            sum += cur;
        } else {
            if (node->left)
                findAndSum(node->left, sum, cur, s);
            if (node->right)
                findAndSum(node->right, sum, cur, s);
        }
        s = s.substr(0, s.size() - 1);
    }
};