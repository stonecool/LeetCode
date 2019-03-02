/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 01:04 - 01:20
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0, i = 0;
    struct ListNode *temp = head;
    
    while (temp)
    {
        ++count;
        temp = temp->next;
    }
    
    if (n > count)
        return head;
    
    if (n == count)
        return head->next;
    
    for (temp = head, i = 0; i < count - n - 1; ++i)
        temp = temp->next;
    if (temp && temp->next)
        temp->next = temp->next->next;
    
    
    return head;
}
