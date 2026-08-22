class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // if i and j has the same ele remove i and add j
        // count the element untill i and j same

        int maxi = 0;
        int j = 0;
        unordered_map<char, int> u;

        for (int i = 0; i < s.size(); i++) {
            u[s[i]]++;

            while(u[s[i]] > 1){
                u[s[j]]--;
                j++;
            }
           


            maxi = max(maxi, (i - j + 1));
        }

        return maxi;
    }
};
