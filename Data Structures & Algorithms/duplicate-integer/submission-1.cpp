class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int,int> u;


        for(int i:nums){
            u[i]++;
        }

        for(auto i:u){
            if(i.second >1)return true;
        }

        return false;
        
    }
};