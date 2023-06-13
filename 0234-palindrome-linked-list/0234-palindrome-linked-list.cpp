class Solution {
public:
    ListNode* reverse1(ListNode* head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        ListNode* small_head = reverse1(head -> next);
        
        head -> next -> next = head;
        head -> next = NULL;
        
        return small_head;
    }

    ListNode* reverse2(ListNode* head)
    {
        ListNode* nex = NULL;
        ListNode* prev = NULL;
        while (head)
        {
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if (head == NULL or head->next == NULL)
        {
            return true;
        }
        
        // ListNode* temp = reverse1(head);
        
        // while (temp != NULL)
        // {
        //     if (temp == head) return true;
        // }
        
        // return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse2(slow->next);
        slow = slow->next;

        while (slow)
        {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};