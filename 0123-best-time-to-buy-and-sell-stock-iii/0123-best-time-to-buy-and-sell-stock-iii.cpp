class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(cap + 1, 0)));
        
        for(int idx = n - 1; idx >= 0; idx--){
            for(int buy = 0; buy < 2; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy == 1){
                        dp[idx][buy][cap] = max(
                            -prices[idx] + dp[idx + 1][0][cap],
                            dp[idx + 1][1][cap]
                        );
                    }
                    else{
                        dp[idx][buy][cap] = max(
                            prices[idx] + dp[idx + 1][1][cap - 1],
                            dp[idx + 1][0][cap]
                        );
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};