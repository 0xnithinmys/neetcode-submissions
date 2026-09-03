class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) return mid;
            //left sorted

            if (nums[l] <= nums[mid]) {
                //target found in left
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
                //right sorted
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    //target found in right
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
