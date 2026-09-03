class Solution {
   public:
    int findMin(vector<int>& nums) {
        // bs l,m,r m>r take right return l
        //  m<r take left return l
        



        int l = 0, r = nums.size()-1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }

        }

        return nums[l];
    }
};
