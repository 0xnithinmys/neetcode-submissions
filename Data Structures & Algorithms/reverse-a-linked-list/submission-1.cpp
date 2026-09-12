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
    ListNode* r(ListNode* p,ListNode* c){
        if(!c)return p;

        ListNode* x = c->next;
        c->next = p;
        p = c;
        c = x;

        return r(p,c);
    }
    ListNode* reverseList(ListNode* head) {

        return r(nullptr,head);
        
    }
};
