/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode tony(0);
        ListNode* p = NULL, *q = NULL, *t = NULL;
        while (head) {
            p = &tony;
            q = p->next;
            t = head;
            head = head->next;
            while (q && q->val val) {
                p = p->next;
                q = q->next;
            }
            t->next = q;
            p->next = t;
        }
        return tony.next;
    }
};