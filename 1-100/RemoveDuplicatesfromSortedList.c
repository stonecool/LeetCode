/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 23:27 - 23:32
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (NULL == head)
        return NULL;
    
    struct ListNode* p = head, *cur = p->next;
    
    while (NULL != cur)
    {
        if (cur->val == p->val)
            // free(cur);
            p->next = cur->next;
        else
            p = cur;
        
        cur = cur->next;
    }
    
    return head;
}
