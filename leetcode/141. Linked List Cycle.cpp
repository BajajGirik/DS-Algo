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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == NULL)
                break;
            
            if(slow->next == fast->next)
                return true;
        }
        
        return false;
    }
};