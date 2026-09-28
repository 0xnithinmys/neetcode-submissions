class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            float r = (x * x) + (y * y);
            pq.push({r, i});
        }
        vector<vector<int>> v;
        for (int i = 0; i < k; i++) {
            int x = pq.top().second;
            v.push_back({points[x][0], points[x][1]});
            pq.pop();
        }

        return v;
    }
};
