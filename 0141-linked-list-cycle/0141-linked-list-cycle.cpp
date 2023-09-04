class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        // base case
        if (head == NULL)
        {
            return false;
        }
        
        ListNode *curr1 = head;
        ListNode *curr2 = head;
        
        while (curr2 != NULL && curr2 -> next != NULL)
        {
            curr2 = curr2 -> next -> next;
            curr1 = curr1 -> next;

            if (curr2 == curr1)
                return true;
        }
        return false;
    }
};