class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxi = INT_MIN,mini =INT_MAX;
        int t = 0;


        for(int i = 0;i<prices.size();i++){

            if(prices[i] < mini){
                mini= prices[i];
                maxi = prices[i];
            }else{
                maxi = prices[i];
            }

            t = max(t,maxi-mini);

        }

        return t;


        
        
    }
};
