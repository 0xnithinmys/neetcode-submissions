class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        unordered_map<int,int> u;


        for(int i=0;i<nums.size() ;i++){
            if(u.find(target-nums[i])!=u.end()){
                return {u[target-nums[i]],i};
            }else{
                u[nums[i]] = i;
            }
        }


        return {-1,-1};
        
    }
};
