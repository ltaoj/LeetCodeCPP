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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num, 0, num.size());
    }
private:
    TreeNode *toBST(vector<int> &num, int headIndex, int tailIndex) {
        if (headIndex == tailIndex)
            return NULL;
        int middleIndex = (headIndex + tailIndex) / 2;
        TreeNode *root = new TreeNode(num.at(middleIndex));
        root->left = toBST(num, headIndex, middleIndex);
        root->right = toBST(num, middleIndex+1, tailIndex);
        return root;
    }
};