class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());

        if (nums2.size() % 2 != 0) {
            return nums2[nums2.size() / 2] ;
        }

        int x = 0;

        x += nums2[nums2.size() / 2];
        x += nums2[nums2.size() / 2-1];

        return x / 2.0;
    }
};
