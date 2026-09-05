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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = list1;
        vector<int> v;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());
        ListNode* newl = nullptr;
        ListNode* tail = nullptr;

        for (int i : v) {
            ListNode* node = new ListNode(i);

            if (newl == nullptr) {
                newl = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        return newl;
    }
};
