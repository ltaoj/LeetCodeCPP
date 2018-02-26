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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        
        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 将slow指针后的链表反序连接
        ListNode* pre = slow->next;
        if (pre->next) {
            ListNode* nex = pre->next;
            pre->next = NULL;
            while (nex) {
                pre = nex->next;
                nex->next = slow->next;
                slow->next = nex;
                nex = pre;
            }
        }
        
        // 将head指针和slow指针连接
        ListNode* p = head, *q = slow->next;
        while (p && q) {
            slow->next = q->next;
            q->next = p->next;
            p->next = q;
            q = slow->next;
            p = p->next->next;
        }
    }
};