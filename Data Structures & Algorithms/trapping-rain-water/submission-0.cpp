class Solution {
public:
    int trap(vector<int>& heights) {

        int l = 0, r = heights.size() - 1;
        int water = 0;
        int lmax = 0, rmax = 0;

        while(l < r){

            if(heights[l] < heights[r]){

                if(heights[l] >= lmax){
                    lmax = heights[l];
                }
                else{
                    water += lmax - heights[l];
                }

                l++;
            }

            else{

                if(heights[r] >= rmax){
                    rmax = heights[r];
                }
                else{
                    water += rmax - heights[r];
                }

                r--;
            }
        }

        return water;
    }
};