class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> u;

        for(int i : nums){
            u[i]++;
        }
int maxi = 0;

        for (int i : nums) {
            if (u.find(i - 1) == u.end()) {
                int num = i;
                int c = 1;

                while (u.find(num + 1) != u.end()) {
                    num++;
                    c++;
                }

                maxi = max(maxi, c);
            }
        }


        return maxi;

        







        
    }
};
