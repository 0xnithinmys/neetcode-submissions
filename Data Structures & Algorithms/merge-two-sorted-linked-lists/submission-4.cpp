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

    void inserttol(ListNode* t) {
        if (dummy == nullptr) {
            dummy = t;
            tail = t;

        } else {
            tail->next = t;
        }

        tail = t;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return dummy;
       if (l1 && !l2) {
            inserttol(l1);
            l1 = l1->next;
        }
        else if (!l1 && l2) {
            inserttol(l2);
            l2 = l2->next;
        }
        else if (l1->val < l2->val) {
            inserttol(l1);
            l1 = l1->next;
        }
        else {
            inserttol(l2);
            l2 = l2->next;
        }
        return mergeTwoLists(l1, l2);
    }
};
