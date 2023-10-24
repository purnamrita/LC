class Solution {
public:
    int helper(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(cap == 0 || idx == n){
            return 0;
        }
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }
        if(buy == 1){
            return dp[idx][buy][cap] = max(
                -prices[idx] + helper(idx + 1, 0, cap, prices, dp),
                helper(idx + 1, 1, cap, prices, dp)
            );
        }
        return dp[idx][buy][cap] = max(
            prices[idx] + helper(idx + 1, 1, cap - 1, prices, dp),
            helper(idx + 1, 0, cap, prices, dp)
        );
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
        return helper(0, 1, cap, prices, dp);
    }
};