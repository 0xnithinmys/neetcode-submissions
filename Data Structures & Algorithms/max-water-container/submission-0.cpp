class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxians = 0;

        for(int i = 0; i < height.size(); i++){
            for(int j = i + 1; j < height.size(); j++){
                
                int h = min(height[i], height[j]);
                int width = j - i;
                int area = h * width;

                maxians = max(maxians, area);
            }
        }
        return maxians;
    }
};