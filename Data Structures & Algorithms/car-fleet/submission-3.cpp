class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // ----1-----2-----3----n----- d
        // pos =[] sp= []
        // carfleet = cars reaches d at same time
        // 1->2->3->4->5->6->7->8->9->10

        // time
        // 1 5 4 : 1,5

        // time
        // stack  top > add else null
        // st.size()



        //7,1  4,2  1,2  0,1
        //3 3 4.5 10   [st.top() < ele] 
        //3 4.5 10

        vector<pair<int,int>> v;

        for(int i = 0;i<speed.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        stack<double> st;

        for (int i = 0; i < speed.size(); i++) {
            int d = target - v[i].first;
            double t = (double)d / v[i].second;

            if (!st.empty()) {
                if (st.top() < t) {
                    st.push(t);
                }
            } else {
                st.push(t);
            }
        }

        return st.size();
    }
};
