/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* copy, *p;
        for (p = head;p;p = p->next->next) {
            copy = new RandomListNode(p->label);
            copy->next = p->next;
            p->next = copy;
        }
        
        for (p = head;p;p = p->next->next) {
            // wrong: p->next->random = p->random->next;
            p->next->random = p->random ? p->random->next : NULL;
        }
        
        RandomListNode tony(0);
        copy = &tony;
        for (p = head;p;p = p->next) {
            copy = copy->next = p->next;
            p->next = p->next->next;
            copy->next = NULL;
        }
        return tony.next;
    }
};