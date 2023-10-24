class Solution {
public:
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        if(buy == 1){
            //buy
            return dp[idx][buy] = max(
                -prices[idx] + helper(idx + 1, 0, prices, dp),
                helper(idx + 1, 1, prices, dp)
            );
        }
        else{
            //sell
            return dp[idx][buy] = max(
                prices[idx] + helper(idx + 2, 1, prices, dp),
                helper(idx + 1, 0, prices, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};