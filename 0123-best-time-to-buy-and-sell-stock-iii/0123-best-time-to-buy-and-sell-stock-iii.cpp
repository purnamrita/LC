class Solution {
public:
    int helper(int idx, int trans, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n || trans == 4){
            return 0;
        }
        if(dp[idx][trans] != -1){
            return dp[idx][trans];
        }
        if(trans % 2 == 0){
            //buy
            return dp[idx][trans] = max(
                -prices[idx] + helper(idx + 1, trans + 1, prices, dp),
                helper(idx + 1, trans, prices, dp)
            );
        }
        else{
            //sell
            return dp[idx][trans] = max(
                prices[idx] + helper(idx + 1, trans + 1, prices, dp),
                helper(idx + 1, trans, prices, dp)
            );
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        return helper(0, 0, prices, dp);
    }
};