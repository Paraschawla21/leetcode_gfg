/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto new1 = new ListNode();
        auto small = new1;
        auto new2 = new ListNode();
        auto big = new2;
        auto root = head;
        while (root)
        {
            if (root->val < x)
            {
                small->next = new ListNode(root->val);
                small = small->next;
            }
            else
            {
                big->next = new ListNode(root->val);
                big = big->next;
            }
            root = root->next;
        }
        small->next = new2->next;
        return new1->next;
    }
};