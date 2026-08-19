class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v;

        vector<int> l(nums.size(), 1);
        vector<int> r(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            l[i] = l[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            r[i] = r[i + 1] * nums[i + 1];
        }

        vector<int> k(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            k[i] = r[i] * l[i];
        }
        return k;
    }
};
