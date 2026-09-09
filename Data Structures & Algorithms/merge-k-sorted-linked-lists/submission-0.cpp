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
        if(lists.size() == 0 )return NULL;

        vector<int> v;


        for(auto i : lists){
            
            ListNode* t = i;
            if(t == nullptr)continue;

            while(t){
                v.push_back(t->val);
                t =t->next;
            }

        }

        sort(v.begin(),v.end());

        vector<ListNode*> r;


        for(auto i : v){
            r.push_back(new ListNode(i));
        }

        if(r.size() == 0)return nullptr;


        for( int i = 1;i<v.size();i++){
            r[i-1]->next = r[i];
        }

        r.back()->next = nullptr;

        return r[0];



        
        
    }
};
