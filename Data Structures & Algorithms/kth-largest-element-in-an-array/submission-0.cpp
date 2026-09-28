class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq;


        for(int i:nums){
            pq.push(i);
        }
        int x = 0;

        for(int i = 0;i<k;i++){
            x = pq.top();
            pq.pop();
            
        }

        return x;
        
    }
};
