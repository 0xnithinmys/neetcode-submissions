class Solution {
public:

    void bfs(int s,vector<bool>& vis,vector<vector<int>>& v){
           queue<int> q;
            vis[s] = true;

            q.push(s);


            while(!q.empty()){
                int n = q.front();
                q.pop();


                for(int nb : v[n] ){
                    if(!vis[nb]){
                        q.push(nb);
                        vis[nb] = true;
                    }
                }
            }
        }
    
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n,false);
        vector<vector<int>> v(n);


        for(auto& i : edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);

        }
        int c = 0;



        for(int i=0;i<n;i++){
            if(!vis[i]){
             bfs(i,vis,v);
            c++;

            }
        }

        return c;

    }
};
