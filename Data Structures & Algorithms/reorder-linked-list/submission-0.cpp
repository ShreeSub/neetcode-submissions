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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev= nullptr;
        ListNode* curr = second;
        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        second = prev;
        ListNode* first = head;
        while(first && second)
        {
            ListNode* fnext = first->next;
            first->next = second;
            ListNode* snext = second->next;
            second->next = fnext;
            first = fnext;
            second = snext;
        }
    }
};
