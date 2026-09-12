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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return  head;
        vector<ListNode*> v;

        ListNode* t = head;

        while (t) {
            v.push_back(t);
            t = t->next;
        }
        for(int i = 0;i+k<=v.size();i+=k){

            reverse(v.begin()+i,v.begin()+i+k);

        }


        for(int i = 1;i<v.size();i++){
            v[i-1]->next = v[i];
        }

        v.back()->next = nullptr;


        return v[0];



    }
};
