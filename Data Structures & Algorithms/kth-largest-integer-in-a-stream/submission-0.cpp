class KthLargest {
public:
        priority_queue<int> pq;
int k = 0;
    KthLargest(int k, vector<int>& nums) {

        this->k = k;

        for(int i : nums){
            pq.push(i);
        }
        
    }
    
    int add(int val) {

        pq.push(val);
        vector<int> v;


        for(int i = 0 ;i<k;i++){
            v.push_back(pq.top());

            pq.pop();

        }


        for(int i = 0;i<k;i++){
            pq.push(v[i]);
        }

        return v[v.size()-1];


        
    }
};
