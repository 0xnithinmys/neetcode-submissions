class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> u;

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;

        vector<int> v;

        for(int i:nums){
            u[i]++;
        }


        for(auto i : u){
            q.push({i.second,i.first});

            if(q.size()>k)q.pop();

        }



        vector<int> r;

        while(!q.empty()){
            int n = q.top().second;

            r.push_back(n);
            q.pop();

        }






        return r;
        
    }
};
