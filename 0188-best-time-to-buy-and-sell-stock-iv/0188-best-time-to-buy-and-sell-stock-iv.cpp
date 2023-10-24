class Solution {
public:
    int helper(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(idx == n || cap == 0){
            return dp[idx][buy][cap] = 0;
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
        else{
            return dp[idx][buy][cap] = max(
                prices[idx] + helper(idx + 1, 1, cap - 1, prices, dp),
                helper(idx + 1, 0, cap, prices, dp)
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0, 1, k, prices, dp);
    }
};