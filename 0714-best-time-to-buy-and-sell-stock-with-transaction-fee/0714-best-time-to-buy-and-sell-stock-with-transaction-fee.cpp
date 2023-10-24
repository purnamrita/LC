class Solution {
public:
    int helper(int idx, int buy, int fee, vector<int>& prices, vector<vector<int>> &dp){
        if(idx == prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        if(buy == 1){
            return dp[idx][buy] = max(
                -prices[idx] - fee + helper(idx + 1, 0, fee, prices, dp),
                helper(idx + 1, 1, fee, prices, dp)
            );
        }
        else{
            return dp[idx][buy] = max(
                prices[idx] + helper(idx + 1, 1, fee, prices, dp),
                helper(idx + 1, 0, fee, prices, dp)
            );
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, fee, prices, dp);
    }
};