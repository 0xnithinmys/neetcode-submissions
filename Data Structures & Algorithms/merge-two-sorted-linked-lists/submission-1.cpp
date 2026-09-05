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
    ListNode* dummy = nullptr;
    ListNode* tail = nullptr;


    void inserttoNode(ListNode* t) {
        if (!dummy) {
            dummy = t;
            tail =t;
        } else {
            tail->next = t;
        }
        tail = t;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode* t = l1;
                inserttoNode(t);
                l1 = l1->next;
            } else {
                ListNode* t = l2;

                inserttoNode(t);
                l2 = l2->next;
            }
        }

        while (l1) {
            inserttoNode(l1);
            l1 = l1->next;
        }
        while (l2) {
            inserttoNode(l2);
            l2 = l2->next;
        }

        return dummy;
    }
};
