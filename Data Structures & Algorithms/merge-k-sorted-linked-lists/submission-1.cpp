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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
       while (lists.size() > 1) {
            vector<ListNode*> mergedLists;

            // Step by 2 to grab pairs of lists
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                // Check if a second list exists to pair with, otherwise it's null
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            
            // Overwrite the original lists with our new, halved array of merged lists
            lists = mergedLists;
        }

        return lists.front();
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2= l2->next;
            }
            tail = tail->next;
        }
        if(l1)
        {
            tail->next = l1;
        }else
        {
            tail->next = l2;
        }
        return dummy->next;
    }
};
