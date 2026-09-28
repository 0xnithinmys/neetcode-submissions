class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0)return 0;

        priority_queue<int> pq;

        for(int i : stones){
            pq.push(i);
        }

        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y){
               continue;
            }else if(x < y){
                pq.push(y-x);
            }else{
                pq.push(x-y);
            }
        }
        int r = 0;
        if(pq.size()==1){
        r = pq.top();
        }

        return r;
        
    }
};
