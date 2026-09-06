class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int,int> u;

        for(int i : nums){
            u[i]++;
            if(u[i] >1){
                return i;
            }
        }

        return -1;


        
        
    }
};
