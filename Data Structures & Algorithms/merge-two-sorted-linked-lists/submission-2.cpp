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
    ListNode* d = nullptr;
    ListNode* t = nullptr;

    void inserttol(ListNode* nn){


        if(d == nullptr){
            d =  nn;
            t =  nn;


        }else{

          
            t->next = nn;

        }
        t = nn;

    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        while(l1 && l2){

            if(l1->val < l2->val){
                inserttol(l1);
                l1 = l1->next;
            }else{
                inserttol(l2);
                l2=l2->next;
            }
        }

        while(l1){
            inserttol(l1);
            l1 = l1->next;
        }
         while(l2){
            inserttol(l2);
            l2 = l2->next;
        }

        return d;
        
    }
};
