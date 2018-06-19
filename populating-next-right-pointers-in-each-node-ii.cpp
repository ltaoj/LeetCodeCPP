/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // 思路就是dummy为虚拟指针
    // 每while循环一次可以处理一层
    // dummy的作用就是保存一个单向链表
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode dummy(-1), *prev;
            prev = &dummy;
            for (auto p = root;p;p = p->next) {
                if (p->left) {
                    prev->next = p->left;
                    prev = prev->next;
                }
                if (p->right) {
                    prev->next = p->right;
                    prev = prev->next;
                }
            }
            root = dummy.next;
        }
    }
};
