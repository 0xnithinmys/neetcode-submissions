class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> v(t.size(),0);

        stack<int> s;

        for(int i = 0;i<t.size();i++){
            while(!s.empty() && t[i] > t[s.top()]){
                int x = s.top();
                s.pop();
                v[x] = i-x;
            }
            s.push(i);
        }
        

        return v;
    }
};
