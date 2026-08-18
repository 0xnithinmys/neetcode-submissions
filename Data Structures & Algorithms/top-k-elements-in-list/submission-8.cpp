class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> u;

        if(k == nums.size())return nums;

        for (int i : nums) {
            u[i]++;
        }

        vector<pair<int,int>> r;

        for (auto i : u) {
            r.push_back({i.first,i.second});
        }

        sort(r.begin(), r.end(), [](auto &a,auto &b){
            return a.second > b.second;
        });

        vector<int> s;

        for (int i =0 ;i<k;i++) {
            s.push_back(r[i].first);
        }

        return s;
    }
};
