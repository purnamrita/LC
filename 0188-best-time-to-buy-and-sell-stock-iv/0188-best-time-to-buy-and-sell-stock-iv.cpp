class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2*k + 1, 0));

        for(int idx = n - 1; idx >= 0; idx--){
            for(int trans = 2*k - 1; trans >= 0; trans--){
                if(trans % 2 == 0){
                    //buy
                    dp[idx][trans] = max(
                        -prices[idx] + dp[idx + 1][trans + 1],
                        dp[idx + 1][trans]
                    );
                }
                else{
                    //sell
                    dp[idx][trans] = max(
                        prices[idx] + dp[idx + 1][trans + 1],
                        dp[idx + 1][trans]
                    );
                }
            }
        }

        return dp[0][0];
    }
};