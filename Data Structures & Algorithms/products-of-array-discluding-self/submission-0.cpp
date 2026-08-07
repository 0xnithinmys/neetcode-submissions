class Solution {

    private:
    int Product(vector<int> nums,int idx){

        int p = 1;

        for(int i = 0 ;i<nums.size();i++){
            if(i!=idx){

            
            p*=nums[i];
            }
        }

        return p;

    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> v;


        for(int i =0;i<nums.size();i++){
            int p = Product(nums,i);
            v.push_back(p);
        }

        return v;

    }
};
