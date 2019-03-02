/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 01:39 -  
/* solution 1
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (NULL == l1)
        return l2;
    if (NULL == l2)
        return l1;
    
    struct ListNode *ret = NULL, *cur = NULL, *temp = NULL;
    
    while (NULL != l1 && NULL != l2)
    {
        if (l1->val < l2 -> val)
        {
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp = l2;
            l2 = l2->next;
        }
        
        if (NULL == ret)
        {
            ret = temp;
            cur = temp;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }
    
    if (NULL == l1)
        cur->next = l2;
    else
        cur->next = l1;
    
    return ret;
}
*/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (NULL == l1)
        return l2;
    if (NULL == l2)
        return l1;

    struct ListNode* ret = NULL, *cur = NULL;
    
    if(l1->val < l2->val)
    {
        ret = l1;
        l1 = l1->next;
    }
    else
    {
        ret = l2;
        l2 = l2->next;
    }

    cur = ret;
    while (NULL != l1 && NULL != l2)
    {
        if(l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        
        cur = cur->next;
    }
    
    if (NULL == l1)
        cur->next = l2;
    else
        cur->next = l1;
    
    return ret;
}
