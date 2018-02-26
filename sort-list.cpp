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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode* s = head, *q = head->next;
        while(q && q->next) {
            s = s->next;
            q = q->next->next;
        }
        
        ListNode* right = sortList(s->next);
        s->next = NULL;
        ListNode* left = sortList(head);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode tony(0);
        ListNode* p = &tony;
        while(left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left) p->next = left;
        if (right) p->next = right;
        return tony.next;
    }
};