/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr)return head;
        vector<Node*> v;
        vector<Node*> k;
        vector<Node*> o;

        Node* t = head;

        while (t) {
            o.push_back(t);
            v.push_back(new Node(t->val));
            k.push_back(t->random);
            t = t->next;
        }

        for (int i = 1; i < v.size(); i++) {
           
            v[i - 1]->next = v[i];
        }
        v.back()->next = nullptr;

        for(int i =0 ;i<v.size();i++){
            if(k[i] == nullptr){
                v[i]->random = nullptr;
            }else{
                for(int j = 0;j<o.size();j++){
                    if(k[i] == o[j]){
                        v[i]->random = v[j];
                        break;
                    }
                }
            }
        }


        return v[0];
    }
};
