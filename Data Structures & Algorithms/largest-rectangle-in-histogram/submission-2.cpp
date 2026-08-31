class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxi = max(maxi, h * w);
            }

            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int w;
            if (st.empty())
                w = heights.size();
            else
                w = heights.size() - st.top() - 1;

            maxi = max(maxi, h * w);
        }

        return maxi;
    }
};