class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        vector<int> after(5, 0);

        for(int idx = n - 1; idx >= 0; idx--){
            vector<int> curr(5, 0);
            for(int trans = 3; trans >= 0; trans--){
                if(trans % 2 == 0){
                    //buy
                    curr[trans] = max(
                        -prices[idx] + after[trans + 1],
                        after[trans]
                    );
                }
                else{
                    //sell
                    curr[trans] = max(
                        prices[idx] + after[trans + 1],
                        after[trans]
                    );
                }
            }
            after = curr;
        }

        return after[0];
    }
};